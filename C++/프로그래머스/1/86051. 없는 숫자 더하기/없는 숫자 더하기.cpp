#include <vector>

using namespace std;

// 1부터 9까지 합은 45이므로 45 - numbers의 합이 결과와 같다.
int solution(vector<int> numbers) {
    int answer = 45;

    for(int number : numbers)
    {
        answer -= number;
    }
    
    return answer;
}