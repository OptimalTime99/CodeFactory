#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    const int maxVal = *max_element(arr.begin(), arr.end());
    int result = maxVal;
    
    // maxVal % num == 0이 모든 원소가 만족할 때 result 값 도출
    // 만족하지 않는다면 maxVal * multiple 하고 다시 반복

    for (int multiple = 1;;)
    {
        result = maxVal * multiple;
        int count = 0;
        
        for (int num : arr)
        {
            if (result % num != 0)
            {
                ++multiple;
                break;
            }
            
            ++count;
            
            if (count == arr.size())
            {
                return result;
            }
        }
        
    }

    
    return result;
}