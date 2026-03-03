// 정렬 1순위: 각 문자열의 n번째 문자 오름차순
// - map에 넣으면 해결
// 정렬 2순위: 사전순

// 우선순위가 높을 수록 나중에 적용해야 한다.

// 1. 벡터에서 각 문자열(key)와 n번째 문자(value)를 map에 넣는다.
// - map은 자동으로 오름차순 정렬하므로, 정렬 1순위 통과
// 2. map에서 n번째 문자인 value를 받아 오름차순해서 그 순서대로 결과에 문자열을 넣는다.
// - 각 문자열의 n번째 문자 오름차순을 함으로서 우선순위를 지킴.

// 2번 과정 풀다가 생각난건데, map<char, vector<string>> 이렇게 한다면?
// 아래와 같이 넣어주고 vector 오름차순 정렬 후, 순서대로 결과에 더해주면 끝.
// {a: [car]} {e: [bed]} {u: [sun]}
// {c: [abce, abcd]} {x: [cdx]}

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<char, vector<string>> orderedMap;
    
    for(string str : strings)
    {
        orderedMap[str[n]].push_back(str);
    }
    
    for(auto& pair : orderedMap)
    {
        sort(pair.second.begin(), pair.second.end());
        
        for(string str : pair.second)
        {
            answer.push_back(str);
        }
    }
    
    return answer;
}
