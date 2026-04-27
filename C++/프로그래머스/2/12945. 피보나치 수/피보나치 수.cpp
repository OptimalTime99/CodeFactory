#include <vector>

using namespace std;

int solution(int n) {
    vector<int> f(n + 1);
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 1234567;
    }
    
    return f[n];
}