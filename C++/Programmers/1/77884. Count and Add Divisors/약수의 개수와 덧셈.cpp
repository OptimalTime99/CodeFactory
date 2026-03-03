#include <string>
#include <vector>

using namespace std;

// 1. left부터 right까지 반복문을 실행한다.
// 2. 약수의 개수를 구한다.
// 3-1. 약수의 개수가 짝수일 경우, 결과에 수를 더한다.
// 3-2. 약수의 개수가 홀수일 경우, 결과에 수를 뺀다.
int solution(int left, int right) {
    int answer = 0;
    
    for(int number = left; number  <= right; ++number)
    {
        vector<int>* vec = new vector<int>();
        for(int d = 1; d * d <= number; ++d)
        {
            if(number % d) continue;
         
            int q = number / d;
            vec->push_back(d);
            
            if (q != d) vec->push_back(q);
        }
        
        if (vec->size() % 2 == 0)
        {
            answer += number;
        } else {
            answer -= number;
        }
        
        delete vec;
        vec = nullptr;
    }
    
    return answer;
}