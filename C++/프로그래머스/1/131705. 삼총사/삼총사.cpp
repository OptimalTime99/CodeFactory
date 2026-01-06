#include <vector>

using namespace std;

// 벡터 내에서 3개의 원소 값을 더했을 때 0이 되는 경우의 수 구하기
// a + b + c = 0
int solution(vector<int> number) {
    int answer = 0;
    int size = number.size();
    
    for(int i = 0; i < size - 2; ++i)
    {
        for(int j = i + 1; j < size - 1; ++j)
        {
            for(int k = j + 1; k < size; ++k)
            {
                if(number[i] + number[j] + number[k] == 0) ++answer;
            }
        }
    }
    
    return answer;
}