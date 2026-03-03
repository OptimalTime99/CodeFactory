// 제일 왼쪽에서 오른쪽으로, 제일 오른쪽에서 왼쪽으로 진행
// 두 선수는 A, B는 동일한 값을 지녀야 한다.
// 결과를 절반 나눠서 구하고 reverse로 뒤집어서 남은 결과 절반을 함께 출력하기
// 0번 인덱스는 물로, 항상 값이 1   // 구분 값으로 사용
// 칼로리 적은 순이 food 인덱스 순

// 1. food 1번 인덱스부터 끝까지 순회
// 2. 값을 2로 나눴을 때 나오는 정수값만 저장: 두 선수는 동일한 값을 지녀야 한다 충족
// 3. food 1번 인덱스부터 food의 인덱스 값만큼 결과에 더한 후, 뒤집은 값도 따로 저장한다.
// 4. 0을 결과에 더한다.
// 5. 뒤집은 값을 결과에 더한다.
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    vector<int> championsFoodCount;
    string answer = "";
    string reverseStr = "";
    
    // 1. food 1번 인덱스부터 끝까지 순회
    for(size_t t = 1; t < food.size(); ++t)
    {
        // 2. 값을 2로 나눴을 때 나오는 정수값만 저장
        championsFoodCount.push_back(food[t] / 2);
    }
    
    // 3. food 1번 인덱스부터 food의 인덱스 값만큼 결과에 더한 후, 뒤집은 값도 따로 저장한다.
    for(size_t t1 = 0; t1 < championsFoodCount.size(); ++t1)
    {
        for(size_t t2 = 1; t2 <= championsFoodCount[t1]; ++t2)
        {
            answer += to_string(t1 + 1);
        }
    }
    
    reverseStr = answer;
    reverse(reverseStr.begin(), reverseStr.end());
    
    // 4. 0을 결과에 더한다.
    answer += "0";
    
    // 5. 뒤집은 값을 결과에 더한다.
    answer += reverseStr;
    
    return answer;
}