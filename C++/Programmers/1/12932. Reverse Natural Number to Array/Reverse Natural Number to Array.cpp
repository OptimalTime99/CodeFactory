#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. 입력값인 숫자를 문자열로 변환한다.
// 2. 문자열을 역순으로 반복문 돌린다.
// 3. 문자열의 각 문자는 아스키 코드값으로 치환되므로 - '0'을 계산하여 숫자로 만들어준다.
vector<int> solution(long long n) {
    vector<int> answer;
    
    string strN = to_string(n);
    
    for(int i = strN.size() - 1; i >= 0; --i)
    {
        answer.push_back(strN[i] - '0');
    }

    return answer;
}