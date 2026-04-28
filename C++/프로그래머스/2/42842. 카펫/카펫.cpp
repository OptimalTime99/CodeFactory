#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    
    for (int h = 3; h * h <= total; ++h) {
        if (total % h == 0) {
            int w = total / h;
            
            if ((w - 2) * (h - 2) == yellow) {
                return {w, h};
            }
        }
    }
    return {};
}

/* 오답 반례: 18, 6 -> [8, 3]
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> primes;
    const int num = brown + yellow;
    
    for (int i = 1; i <= num; ++i)
    {
        if (num % i == 0)
        {
            primes.push_back(i);
        }
    }
    
    
    int middleIndex = primes.size() / 2;
    int middleNum = primes[middleIndex];
    int middleNum2 = primes[middleIndex - 1];
    
    if (primes.size() % 2 == 0)
    {
        return {middleNum, middleNum2};
    }

    return {middleNum, middleNum};
    
}
*/
/*
1, 2, 3, 4, 6, 12
    
1, 3, 9

1, 2, 3, 4, 6, 8, 12, 16, 24, 48
    
홀수개일 때는 [중간값, 중간값]
짝수개일 때는 [중간값 + 1, 중간값] 
*/

    