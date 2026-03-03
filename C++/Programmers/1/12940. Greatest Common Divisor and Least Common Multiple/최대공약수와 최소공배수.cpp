#include <vector>

using namespace std;

// 최대공약수(GCD):
// 두 수 n, m을 모두 나누어떨어지게 하는 수 중 가장 큰 값
// 작은 수부터 1까지 내려가며
// n과 m이 모두 나누어떨어지는 첫 번째 수가 최대공약수

// 최소공배수(LCM):
// n과 m을 곱한 값을 최대공약수로 나눈 값
void swap(int& n, int& m) {
    int temp = n;
    n = m;
    m = temp;
}


vector<int> solution(int n, int m) {
    if(n > m) swap(n, m);
    
    vector<int> answer;
    const int N = n;
    const int M = m;
    
    long long b = 1LL * n * m;
    
    int a = 1;
    while(n > 0) {
        if (N % n == 0 && M % n == 0) {
            a = n;
            break;
        }
        n--;
    }
    
    long long c = b / a;
    
    answer.push_back(a);
    answer.push_back((int)c);
    
    return answer;
}    
    
