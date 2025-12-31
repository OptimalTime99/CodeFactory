#include <vector>
using namespace std;

// 유클리드 호제법
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

vector<int> solution(int n, int m) {
    int g = gcd(n, m);
    long long l = (long long)n / g * m; // overflow 방지
    return { g, (int)l };
}
