#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string pronunciation[4] = {"aya", "ye", "woo", "ma"};
    
    // 1. 검사할 문자열 리스트(babbling)를 처음부터 끝까지 하나씩 순회한다.
    for(string word : babbling) {
        
        // 2. 현재 단어 검사를 위해 커서(j)는 0, 직전 발음(last_type)은 -1로 초기화한다.
        int j = 0;          
        int last_type = -1; 
        bool is_possible = true;
        
        // 3. 커서(j)가 단어의 끝에 도달할 때까지 반복한다.
        while(j < word.length()) {
            bool found = false; // 이번 위치에서 발음을 찾았는지 여부
            
            // 4. 현재 위치에서 4가지 발음 중 일치하는 것이 있는지 확인한다.
            for(int k = 0; k < 4; k++) {
                
                // 5. 현재 커서 위치(j)의 문자열이 k번째 발음과 일치하는지 확인한다.
                if(word.substr(j, pronunciation[k].length()) == pronunciation[k]) {
                    
                    // 6. [실패 조건 1] 일치하더라도, 직전 발음과 같다면 연속 발음이므로 실패 처리한다.
                    if(last_type == k) {
                        is_possible = false;
                        break; 
                    }
                    
                    // 7. [성공] 연속이 아니라면 커서를 길이만큼 점프시키고, 현재 발음을 기억한다.
                    j += pronunciation[k].length();
                    last_type = k;
                    found = true;
                    break; // 찾았으므로 다음 발음 검사는 생략하고 while문으로 돌아간다.
                }
            }
            
            // 8. [실패 조건 2] 4개를 다 확인했는데도 일치하는 발음이 없거나, 연속 발음으로 실패했다면 중단한다.
            if(!found || !is_possible) {
                is_possible = false;
                break;
            }
        }
        
        // 9. 끝까지 확인했고 실패하지 않았다면 정답을 1 증가시킨다.
        if(is_possible) answer++;
    }
    
    // 10. 최종 정답을 반환한다.
    return answer;
}