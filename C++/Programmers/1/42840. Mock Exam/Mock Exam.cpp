// 1. 1~3번 수포자의 패턴을 정리한다.
// 2. {N번 수포자, 맞춘 개수} 형태의 맵을 만든다.
// 3. 답안의 순서에 맞게 패턴을 대입해 맞춘 개수를 카운팅하여 저장한다.
// 4. max값과 카운팅한 값이 같으면 결과에 더한다.
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 1. 1~3번 수포자의 패턴을 정리한다.
    vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    // 2. {N번 수포자, 맞춘 개수} 형태의 맵을 만든다.
    map<int, int> countingMap = {
        {1, 0},
        {2, 0},
        {3, 0}
    };
    
    // 3. 답안의 순서에 맞게 패턴을 대입해 맞춘 개수를 카운팅하여 저장한다.
    for(size_t t = 0; t < answers.size(); ++t)
    {
        if(answers[t] == patterns[0][t % patterns[0].size()]) countingMap[1]++;
        if(answers[t] == patterns[1][t % patterns[1].size()]) countingMap[2]++;
        if(answers[t] == patterns[2][t % patterns[2].size()]) countingMap[3]++;
    }
    
    // 4. max값과 카운팅한 값이 같으면 결과에 더한다.
    auto maxIt = max_element(countingMap.begin(), countingMap.end(), 
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );
    
    for(auto const& [key, val] : countingMap)
    {
        if(val == maxIt->second)
        {
            answer.push_back(key);
        }
    }
    
    return answer;
}