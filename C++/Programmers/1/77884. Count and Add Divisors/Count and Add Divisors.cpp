// 약수 개수가 보통 짝수인데, 제곱수만 sqrt(n)이 짝이 안 맞아서 홀수가 된다.
// → 제곱수면 결과에서 빼고, 아니면 결과에서 더하면 끝나는 문제이다. O(N)
#include <cmath>

int solution(int left, int right) {
    int answer = 0;

    for (int n = left; n <= right; ++n) {
        int r = (int)std::sqrt(n);
        bool isSquare = (r * r == n);
        answer += isSquare ? -n : n;
    }
    return answer;
}
