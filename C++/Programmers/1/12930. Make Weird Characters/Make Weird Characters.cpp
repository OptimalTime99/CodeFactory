#include <string>
#include <cctype>   // toupper, tolower
using namespace std;

// 1. 문자열을 문자 단위로 나눈다.
// 2. 공백을 기준으로 짝수/홀수 인덱스를 판단한다.
// 3-1. 문자의 인덱스가 짝수라면 대문자로 변경한다.
// 3-2. 문자의 인덱스가 홀수라면 소문자로 변경한다.
string solution(string s) {
    string answer = "";
    int idx = 0; // 단어 내 인덱스

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (c == ' ') {
            idx = 0; // 단어가 끝났으니 인덱스 리셋
            answer += c;
            continue;
        }

        if (idx % 2 == 0) {
            c = toupper(c);
        } else {
            c = tolower(c);
        }

        answer += c;
        idx++;
    }

    return answer;
}
