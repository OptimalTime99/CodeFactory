// 문자열을 나누지 않고 인덱스 순회하며 계산
// - 분해했다고 한 문자열의 첫 글자가 x가 된다.
// - 제한사항: 만약 두 횟수가 다른 상태에서 더 이상 읽을 글자가 없다면, 역시 지금까지 읽은 문자열을 분리하고, 종료합니다.
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    // 현재 세고 있는 부분 문자열의 첫 글자
    char x = s[0]; 
    int x_count = 0;     // x의 개수
    int other_count = 0; // x가 아닌 글자의 개수
    
    for (int i = 0; i < s.length(); ++i) {
        // 1. 새로운 분해가 시작되는 시점이라면 기준 문자(x) 갱신
        if (x_count == 0 && other_count == 0) {
            x = s[i];
        }
        
        // 2. 개수 세기
        if (s[i] == x) {
            ++x_count;
        } else {
            ++other_count;
        }
        
        // 3. 두 횟수가 같아지면 분해
        if (x_count == other_count) {
            ++answer;
            // 카운터 초기화 (다음 루프에서 새로운 x를 잡게 됨)
            x_count = 0;
            other_count = 0;
        }
    }
    
    // 4. 카운트가 남아있는 경우 문자열 분리
    if (x_count != other_count) {
        ++answer;
    }
    
    return answer;
}
