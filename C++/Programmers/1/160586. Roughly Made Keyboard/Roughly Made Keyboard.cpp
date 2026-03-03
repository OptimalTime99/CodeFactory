#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> minPress;

    // 1. 모든 keymap을 분석해 각 문자의 최소 타수 계산
    for (const string& key : keymap) {
        for (int i = 0; i < key.size(); ++i) {
            char c = key[i];
            if (minPress.find(c) == minPress.end()) {
                minPress[c] = i + 1;
            } else {
                minPress[c] = min(minPress[c], i + 1);
            }
        }
    }

    // 2. targets를 돌며 총합 계산
    for (const string& target : targets) {
        int total = 0;
        bool possible = true;

        for (char c : target) {
            if (minPress.find(c) != minPress.end()) {
                total += minPress[c];
            } else {
                // 키맵에 없는 문자가 있다면 바로 실패
                possible = false;
                break;
            }
        }
        
        answer.push_back(possible ? total : -1);
    }

    return answer;
}