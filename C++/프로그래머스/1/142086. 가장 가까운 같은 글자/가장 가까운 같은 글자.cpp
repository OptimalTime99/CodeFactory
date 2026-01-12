// 1. 문자열을 0번째부터 끝까지 돈다
// 2. 현재 글자 c가 map에 존재하는지 확인한다.
// 2-1. 존재하지 않는다면, -1을 answer에 추가한다.
// 2-2. 존재한다면, 거리 = 현재 인덱스 - 기록된 인덱스를 계산해서 answer에 추가한다.
// 3. 현재 글자 c의 위치 정보를 현재 인덱스로 갱신한다.

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> history; // { 글자: 마지막 위치 인덱스 } 형태
    
    // 1. 문자열을 0번째부터 끝까지 돈다
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        
        // 2. 현재 글자 c가 map에 존재하는지 확인한다.
        if(history.find(c) == history.end())
        {
            // 2-1. 존재하지 않는다면, -1을 answer에 추가한다.
            answer.push_back(-1);
        } else {
            // 2-2. 존재한다면, 거리 = 현재 인덱스 - 기록된 인덱스를 계산해서 answer에 추가한다.
            int last_index = history[c];
            int distance = i - last_index;
            answer.push_back(distance);
        }
        
        // 3. 현재 글자 c의 위치 정보를 현재 인덱스로 갱신한다.
        history[c] = i;
    }
    
    return answer;
}