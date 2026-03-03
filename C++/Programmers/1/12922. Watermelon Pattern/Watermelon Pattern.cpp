#include <string>

using namespace std;

// 1부터 n까지 반복할 때,
// index가 짝수라면 "수"를 결과에 더한다.
// index가 홀수라면 "박"을 결과에 더한다.
string solution(int n) {
    string answer = "";
    
    for(int index = 0; index < n; ++index)
    {
        if(index % 2 == 0)
        {
            answer += "수";
        } else {
            answer += "박";
        }
    }
    
    return answer;
}