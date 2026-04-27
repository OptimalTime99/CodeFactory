#include <vector>

using namespace std;

vector<long long> memo(100001, -1);

int fibo(int n)
{
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1234567;
    
    return memo[n];
}

int solution(int n) {
    return fibo(n);
}