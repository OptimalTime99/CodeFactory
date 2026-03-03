#include <vector>
#include <cmath>

using namespace std;

// 1. n이 1이 될때까지
//    1-1. n % 3의 결과를 배열에 넣는다.
//    1-2. n / 3을 한다.
// 2. 배열에 n을 넣는다. (이때의 n은 1)
// 3. 배열은 이미 앞뒤 반전이 일어난 상태이므로 첫번째 값부터 반복문을 돌려 값을 결과에 더한다.
//    더하는 값 = 현재 인덱스의 값 * 3^(배열의 크기 - 인덱스 - 1)
int solution(int n) {
    int answer = 0;
    const int BASE = 3; 
    vector<int> numbers;

    while(n != 1)
    {
        numbers.push_back(n % BASE);
        n /= BASE;
    }

    numbers.push_back(n);

    for(int i = 0; i < numbers.size(); ++i)
    {
        answer += numbers[i] * pow(BASE, numbers.size() - i - 1);
    }

    return answer;
}
