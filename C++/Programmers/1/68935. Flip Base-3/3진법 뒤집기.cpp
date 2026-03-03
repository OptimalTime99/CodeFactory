#include <vector>
using namespace std;

// 1. n이 0이 될 때까지 반복한다.
//    1-1. n을 3으로 나눈 나머지를 배열에 저장한다.
//         → 3진법 변환 과정이며, 이 값들은 뒤집힌 순서로 저장된다.
//    1-2. n을 3으로 나눈 몫으로 갱신한다.
// 2. 배열에는 뒤집힌 3진수 각 자리가 저장되어 있다.
// 3. 배열의 마지막 인덱스부터 순회하며 10진수로 복원한다.
//    3-1. 현재 자리값(place)은 3의 거듭제곱을 의미한다.
//    3-2. answer += 현재 자리 숫자 × place
//    3-3. 다음 자리를 위해 place에 3을 곱한다.
int solution(int n) {
    vector<int> numbers;
    const int BASE = 3;
    while (n > 0) {
        numbers.push_back(n % BASE);
        n /= BASE;
    }

    int answer = 0;
    int place = 1;
    for (int i = (int)numbers.size() - 1; i >= 0; --i) {
        answer += numbers[i] * place;
        place *= BASE;
    }

    return answer;
}