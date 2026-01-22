// 1. 약수의 개수를 구한다.
// 2. limit 초과인 originalPower는 기본 power로 대체한다.
// 3. originalPower를 결과에 더한다. 
#include <string>
#include <vector>

using namespace std;

int getDivisorCount(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int count = 1;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int exponent = 0;
            
            while (n % i == 0) {
                n /= i;
                exponent++;
            }
            
            count *= (exponent + 1);
        }
    }

    if (n > 1) {
        count *= 2;
    }

    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; ++i)
    {
        int originalPower = getDivisorCount(i);
        if(originalPower > limit) 
        {
            originalPower = power;
        }
        
        answer+=originalPower;
    }
    
    return answer;
}