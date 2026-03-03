#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    long long x = sqrt(n);
    
    if(n == pow(x, 2)) answer = pow(x + 1, 2);
    
    return answer;
}