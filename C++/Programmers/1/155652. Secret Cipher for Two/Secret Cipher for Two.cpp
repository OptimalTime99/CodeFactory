#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    constexpr int ALPHABET_SIZE = 26;
    
    // 1. 알파벳 개수만큼 vector를 1로 초기화한다.
    vector<int> alphabet_flags(ALPHABET_SIZE, 1);
    
    // 2. skip 알파벳에 해당하는 인덱스값을 0으로 설정한다.
    for (char skip_alphabet : skip)
    {
        alphabet_flags[skip_alphabet - 'a'] = 0;
    }
    
    // 3. s의 처음부터 끝까지 순회한다.
    for (char current_alphabet : s)
    {
        int current_alphabet_index = current_alphabet - 'a';
        
        // 4. 유효한 문자를 index개 만큼 찾을 때까지 한 칸씩 이동한다.
        int valid_count = 0; // 찾은 유효한 문자의 개수
        int offset = 0;      // 현재 위치에서 실제로 이동한 거리
        
        while (valid_count < index)
        {
            offset++;
            
            int check_index = (current_alphabet_index + offset) % ALPHABET_SIZE;
            
            if (alphabet_flags[check_index] == 1) {
                valid_count++;
            }
        }
        
        // 5. 최종적으로 이동한 위치를 이용해 문자를 구한다.
        int final_index = (current_alphabet_index + offset) % ALPHABET_SIZE;
        answer += 'a' + final_index;
    }
    
    return answer;
}