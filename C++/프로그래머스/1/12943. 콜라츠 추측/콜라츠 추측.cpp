#include <string>
#include <vector>

using namespace std;

// 1. 주어진 수가 1인 경우에 0을 반환한다.
// 2. 입력된 수가 짝수라면 2로 나눈다. 작업 수를 1 더한다.
// 3. 입력된 수가 홀수라면 3을 곱하고 1을 더한다. 작업 수를 1 더한다.
// 4. 작업 수가 500이 될 때까지 수가 1이 되지 않으면 -1을 반환한다.
// (숫자가 너무 커진다 싶으면 long long으로 계산하자)
int solution(int num) {
    if (num == 1) return 0;
    
    long long value = num;
    int answer = 0;
    
    while(value != 1)
    {
        if (value % 2 == 0)
        {
            value /= 2;
        } else {
            value = value * 3 + 1;
        }
        
        ++answer;
        if (answer == 500) return -1;
    }
    return answer;
}