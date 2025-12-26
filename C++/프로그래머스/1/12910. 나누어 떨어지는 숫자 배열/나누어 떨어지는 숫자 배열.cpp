#include <algorithm>
#include <vector>

using namespace std;

// 1. divisor가 1이라면 arr을 오름차순 반환하고 종료한다.
// 2. arr의 각 원소를 divisor로 나누었을 때, 나누어 떨어진다면 answer에 넣는다.
// 3-1. answer이 비어있다면 -1을 넣어줘 나누어 떨어지는 element가 하나도 없는 것을 표현한다.
// 3-2. answer이 비어있지 않다면 오름차순 정렬한다. 
// 4. answer를 반환하고 종료한다.
vector<int> solution(vector<int> arr, int divisor) {
    if(divisor == 1)
    {
        sort(arr.begin(), arr.end());
        return arr;
    }
    
    vector<int> answer;
    
    for (size_t t = 0; t < arr.size(); ++t)
    {
        if(arr[t] % divisor == 0) answer.push_back(arr[t]);
    }
    
    if(answer.size() == 0) 
    {
        answer.push_back(-1);
    } else {
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}