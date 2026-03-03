/*
1. 배열 commands 길이만큼 2~4 과정을 반복한다.
2. 배열 array를 i번째 숫자부터 j번째 숫자까지 잘라 새 배열을 만든다.
3. 2에서 나온 배열을 오름차순으로 정렬한다.
4. 3에서 나온 배열의 k번째 수를 구하여 결과 배열에 넣는다.
5. 결과 배열을 반환한다.
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // 1. 배열 commands 길이만큼 2~4 과정을 반복한다.
    for(auto command : commands) {
        
        // 2. 배열 array를 i번째 숫자부터 j번째 숫자까지 잘라 새 배열을 만든다.
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> sub(array.begin() + i - 1, array.begin() + j);
        
        // 3. 2에서 나온 배열을 오름차순으로 정렬한다.
        sort(sub.begin(), sub.end());
        
        // 4. 3에서 나온 배열의 k번째 수를 구하여 결과 배열에 넣는다.
        answer.push_back(sub[k - 1]);
    }
    
    // 5. 결과 배열을 반환한다.
    return answer;
}