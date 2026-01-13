// 교환해야 하는 빈 병의 개수: n
// 교환 조건: a
// 받는 값: b
// 받을 수 있는 콜라의 병 수: answer

// 빈 병(n)이 교환 가능한 최소 개수(a)보다 크거나 같을 때까지만 반복한다.
// 1. 교환으로 받게 될 새 콜라 병의 수 계산한다.
// 2. 교환하고 남은 빈 병의 수를 구한다.
// 3. 정답에 받은 콜라 수 추가한다.
// 4. 다음 루프를 위해 현재 빈 병 개수 갱신한다.
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    // 빈 병(n)이 교환 가능한 최소 개수(a)보다 크거나 같을 때까지만 반복한다.
    while (n >= a)
    {
        // 1. 교환으로 받게 될 새 콜라 병의 수 계산한다.
        int received = (n / a) * b;
        
        // 2. 교환하고 남은 빈 병의 수를 구한다.
        int remainder = n % a;
        
        // 3. 정답에 받은 콜라 수 추가한다.
        answer += received;
        
        // 4. 다음 루프를 위해 현재 빈 병 개수 갱신한다.
        n = remainder + received;
    }
    
    return answer;
}


