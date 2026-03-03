#include <vector>

using namespace std;

// 반복문의 종료 조건: n
vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    for (int i = 1; i <= n; ++i)
    {
        answer.push_back(x * i);
    }
    
    return answer;
}