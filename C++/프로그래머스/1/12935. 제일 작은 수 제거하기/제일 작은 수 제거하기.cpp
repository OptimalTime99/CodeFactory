#include <algorithm>
#include <vector>

using namespace std;

// 1. 배열의 길이가 1인 경우, [-1]을 반환한다.
// 내림차순 정렬해서 마지막 값 제거하면 안됨.
// 2. 말 그대로 가장 작은 수 찾아 제거한다.
vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return {-1};
    
    int minNumber = *min_element(arr.begin(), arr.end());
    
    auto it = find(arr.begin(), arr.end(), minNumber);
    
    if (it != arr.end())
    {
        arr.erase(it);
    }
    
    return arr;
}