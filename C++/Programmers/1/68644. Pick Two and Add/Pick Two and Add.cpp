
// 1. 중첩 반복문으로 두 수의 합을 더해 set에 추가한다.
// - set은 자동으로 중복이 제거되고 정렬되므로 이 문제에 제격이라 생각됨.
// 2. set에 있는 값을 answer에 추가한다.
// 3. answer를 오름차순 정렬한다.
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> sumSet;
    const size_t NUMBERS_SIZE = numbers.size();
    
    // 1. 중첩 반복문으로 두 수의 합을 더해 set에 추가한다.
    for(size_t t1 = 0; t1 < NUMBERS_SIZE; ++t1)
    {
        for(size_t t2 = t1 + 1; t2 < NUMBERS_SIZE; ++t2)
        {
            sumSet.insert(numbers[t1] + numbers[t2]);
        }
    }
    
    // 2. set에 있는 값을 answer에 추가한다.
    for(int sumNumber : sumSet)
    {
        answer.push_back(sumNumber);
    }
    
    // 3. answer를 오름차순 정렬한다.
    sort(answer.begin(), answer.end());
    
    return answer;
}




