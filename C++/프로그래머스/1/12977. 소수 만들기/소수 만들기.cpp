// 소수의 조건 1: 1보다 커야 한다.
// 소수의 조건 2: 약수가 오직 1과 자기 자신뿐이어야 한다.
// 주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수 구하기

// 1. 에라토스테네스의 체로 소수 판별 배열 미리 만든다.
// - nums의 원소는 최대 1000이므로, 3개의 합은 최대 3000을 넘지 않는다.
// - 처음엔 0과 1을 제외한 모든 수가 소수라고 가정한다.
// - 2부터 제곱근까지 반복하며 배수들을 제거한다.
//   - 특정 수가 소수라면 그 수의 배수는 소수가 아니다.
// 2. 3중 반복문으로 3개의 수를 더한다.
#include <set>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    // 1. 에라토스테네스의 체로 소수 판별 배열 미리 만든다.
    // - nums의 원소는 최대 1000이므로, 3개의 합은 최대 3000을 넘지 않는다.
    const int MAX_SUM = 3000;
    
    // - 처음엔 0과 1을 제외한 모든 수가 소수라고 가정한다.
    vector<bool> isPrime(MAX_SUM + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    // - 2부터 제곱근까지 반복하며 배수들을 제거한다.
    for(int i = 2; i * i <= MAX_SUM; ++i)
    {
        // - 특정 수가 소수라면 그 수의 배수는 소수가 아니다.
        if(isPrime[i])
        {
            for(int j = i * i; j < MAX_SUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    // 2. 3중 반복문으로 3개의 수를 더한다.
    const size_t NUMS_SIZE = nums.size();
    
    for(size_t t1 = 0; t1 < NUMS_SIZE; t1++)
    {
        for(size_t t2 = t1 + 1; t2 < NUMS_SIZE; t2++)
        {
            for(size_t t3 = t2 + 1; t3 < NUMS_SIZE; t3++)
            {
                int sum = nums[t1] + nums[t2] + nums[t3];
                
                if (isPrime[sum] == true) {
                    answer++;
                }
            }
        }
    }

    return answer;
}