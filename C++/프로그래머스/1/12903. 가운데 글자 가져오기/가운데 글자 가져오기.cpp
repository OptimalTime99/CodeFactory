#include <string>

using namespace std;

// 해당하는 인덱스 값 가져오기
// 1. 문자열의 길이가 홀수라면:
//  문자열의 길이 / 2 = 해당하는 인덱스의 1개의 문자 값
// 2. 문자열의 길이가 짝수라면:
//  문자열의 길이 / 2 - 1 = 해당하는 인덱스부터 2개의 문자 값
string solution(string s) {
    string answer = "";
    int size = s.length();
    
    if(size % 2 == 1)
    {
        answer =  s.substr(size / 2, 1);
    } else {
        answer =  s.substr(size / 2 - 1, 2);
    }
    
    return answer;
}