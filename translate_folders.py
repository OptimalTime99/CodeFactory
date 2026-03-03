import os
import json
import re
import argparse
from datetime import datetime

# Path to the Programmers dictionary generated earlier
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
# Expect programmers-dict.json to be in the SAME directory as this Python script
DICT_PATH = os.path.join(SCRIPT_DIR, 'programmers-dict.json')

# Basic platform and tier mappings
KOR_TO_ENG_DICT = {
    "백준": "Baekjoon",
    "프로그래머스": "Programmers",
    "SW Expert Academy": "SWEA",
    "브론즈": "Bronze",
    "실버": "Silver",
    "골드": "Gold",
    "플래티넘": "Platinum",
    "다이아몬드": "Diamond",
    "루비": "Ruby",
    "마스터": "Master",
    "언랭크": "Unrated",
    "레벨": "Level",
    "D1": "D1", "D2": "D2", "D3": "D3", "D4": "D4",
    "D5": "D5", "D6": "D6", "D7": "D7", "D8": "D8"
}

def load_programmers_dict():
    if os.path.exists(DICT_PATH):
        try:
            with open(DICT_PATH, 'r', encoding='utf-8') as f:
                return json.load(f)
        except Exception as e:
            print(f"Error reading JSON file at {DICT_PATH}: {e}")
            import sys
            sys.exit(1)
    
    print(f"\n[ERROR] Missing Dictionary File!")
    print(f"I could not find 'programmers-dict.json' at:\n  {DICT_PATH}")
    print("Please MAKE SURE you copy BOTH 'translate_folders.py' AND 'programmers-dict.json' into the same directory before running this script.")
    import sys
    sys.exit(1)

def translate_name(name, programmers_dict, is_file=False, root_path=""):
    ext = ""
    # Extract file extension if this is a file
    if is_file:
        name, ext = os.path.splitext(name)
        
    # 1. Translate Platforms and Tiers exactly
    translated_name = name
    for ko, en in KOR_TO_ENG_DICT.items():
        translated_name = translated_name.replace(ko, en)

    # 2. Extract Problem ID from parent folder if available
    extracted_id = None
    is_programmers = False
    if root_path:
        is_programmers = "프로그래머스" in root_path or "Programmers" in root_path
        parent_folder = os.path.basename(root_path)
        id_match = re.search(r'^(\d+)\.', parent_folder)
        if id_match:
            extracted_id = id_match.group(1)

    # 3. Translate titles containing Korean characters OR fix messed up Fallback names
    korean_regex = re.compile(r'[ㄱ-ㅎㅏ-ㅣ가-힣]')
    is_fallback_name = is_file and "_Problem" in translated_name and bool(re.match(r'^\d{8}_Problem$', translated_name))

    if korean_regex.search(translated_name) or is_fallback_name:
        # Specific logic for problem folders like "1234. 한글제목"
        match = re.match(r'^(\d+\.\s*)(.*)', translated_name)
        if match:
            prefix = match.group(1)
            rest_of_title = match.group(2).strip()
            problem_id = prefix.replace('.', '').strip()

            if problem_id in programmers_dict:
                translated_name = prefix + programmers_dict[problem_id]
            elif rest_of_title in programmers_dict:
                translated_name = prefix + programmers_dict[rest_of_title]
            else:
                date_str = datetime.now().strftime("%Y%m%d")
                translated_name = f"{prefix}{date_str}_Problem"
        else:
            # Format doesn't match "ID. Title", e.g. purely "한글제목.cpp" or "20260227_Problem.cpp"
            pure_name = translated_name.strip()
            if is_programmers and extracted_id and extracted_id in programmers_dict:
                translated_name = programmers_dict[extracted_id]
            elif pure_name in programmers_dict and not is_fallback_name:
                translated_name = programmers_dict[pure_name]
            else:
                if is_fallback_name:
                    translated_name = pure_name
                else:
                    date_str = datetime.now().strftime("%Y%m%d")
                    translated_name = f"{date_str}_Problem"

    return translated_name + ext

def rename_directories(target_dir):
    if not os.path.exists(target_dir):
        print(f"Error: Directory '{target_dir}' does not exist.")
        return

    programmers_dict = load_programmers_dict()
    
    print(f"Traversing directory: {target_dir}")
    print("-" * 50)
    
    # We must traverse bottom-up to rename deeply nested folders first without breaking upper paths
    rename_count = 0
    file_rename_count = 0
    for root, dirs, files in os.walk(target_dir, topdown=False):
        # Skip hidden or environment directories
        if '.git' in root or 'node_modules' in root:
            continue

        # First, rename files inside this directory (including .cpp, .java, etc)
        for file_name in files:
            if file_name.startswith('.'):
                continue
            
            new_file_name = translate_name(file_name, programmers_dict, is_file=True, root_path=root)
            if new_file_name != file_name:
                old_path = os.path.join(root, file_name)
                new_path = os.path.join(root, new_file_name)
                
                print(f"Renaming File: '{file_name}' -> '{new_file_name}'")
                try:
                    os.rename(old_path, new_path)
                    file_rename_count += 1
                except OSError as e:
                    print(f"  Failed to rename file {old_path}: {e}")

        for dir_name in dirs:
            # Skip hidden folders like .git
            if dir_name.startswith('.'):
                continue

            new_name = translate_name(dir_name, programmers_dict, is_file=False, root_path=root)
            if new_name != dir_name:
                old_path = os.path.join(root, dir_name)
                new_path = os.path.join(root, new_name)
                
                print(f"Renaming Dir: '{dir_name}' -> '{new_name}'")
                
                # Check for target collision
                if os.path.exists(new_path):
                    print(f"  Warning: Target folder '{new_name}' already exists! Merging contents...")
                    # Naively move files into the existing target
                    import shutil
                    for src_item in os.listdir(old_path):
                        src_path = os.path.join(old_path, src_item)
                        dst_path = os.path.join(new_path, src_item)
                        try:
                            shutil.move(src_path, dst_path)
                        except OSError as e:
                            print(f"    Failed to move {src_item}: {e}")
                    # Delete the now-empty old directory
                    try:
                        os.rmdir(old_path)
                    except OSError as e:
                        print(f"    Failed to remove old folder {old_path}: {e}")
                else:
                    try:
                        os.rename(old_path, new_path)
                        rename_count += 1
                    except OSError as e:
                        print(f"  Failed to rename dir to {new_name}: {e}")
                        if "WinError 5" in str(e) or "WinError 32" in str(e):
                            print("  -> ERROR: Access is denied. Please make sure no other program (like VS Code, Terminal, or File Explorer) is open in this directory.")
                        
    print("-" * 50)
    print(f"Translation completed. Folders renamed: {rename_count}, Files renamed: {file_rename_count}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Translate Korean BaekjoonHub folders to English.")
    parser.add_argument("target_dir", help="Path to the repository to translate")
    
    args = parser.parse_args()
    rename_directories(args.target_dir)
