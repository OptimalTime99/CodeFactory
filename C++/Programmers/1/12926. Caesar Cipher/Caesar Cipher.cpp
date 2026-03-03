// 1. 문자열의 각 문자를 아스키 코드로 변환한다.
//    - 문자가 공백인 경우, 변환하지 않고 바로 더한다.
// 2. 아스키 코드값에 거리를 더한다.
//    - 더한 값이 'Z'보다 크고 'a'보다 작다면 다시 알파벳의 크기를 빼서 'A'부터 시작하게 한다.
//    - 더한 값이 'z'보다 크다면 다시 알파벳의 크기를 빼서 다시 'a'부터 시작하게 한다.
// 3. 아스키 코드를 다시 문자로 변환한다.
// 4. 문자를 결과에 더한다.

// 원래 문자가 소문자인지, 대문자인지 판별하는 로직이 빠졌음.

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    const int ALPHABET_SIZE = 26;
    
    for(char c : s)
    {
        if(c == ' ') 
        {
            answer += c;
            continue;
        }
        
        // 기준점 정하기: 소문자면 'a', 대문자면 'A'
        char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
        
        // c - base로 0~25 사이의 숫자로 변환해서 알파벳 표현
        // n만큼 이동
        // 알파벳 크기 넘어가면 다시 0부터 시작하는 것을 나머지 연산으로 계산
        // base를 다시 더해 아스키코드 범위로 복구
        answer += base + (c - base + n) % ALPHABET_SIZE;
    }
    
    return answer;
}

