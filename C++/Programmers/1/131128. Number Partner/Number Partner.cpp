#include <map>
#include <string>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    // Key: 숫자문자, Value: 개수, 정렬: Key 기준 내림차순 ('9' -> '0')
    map<char, int, greater<int>> xMap;
    map<char, int, greater<int>> yMap;
    
    // 1. map 내림차순으로 각 문자열 X, Y를 분해한다.
    for(char c : X) xMap[c]++;
    for(char c : Y) yMap[c]++;
    
    // 2. xMap을 기준으로 순회한다.
    for(auto iter = xMap.begin(); iter != xMap.end(); iter++) {
        char key = iter->first;    // 현재 숫자
        int xCount = iter->second; // X에 있는 개수
        
        // 3. 같은 원소가 yMap에 존재하는지 확인
        if(yMap.count(key)) {
            int yCount = yMap[key]; // Y에 있는 개수
            
            // 두 개수 중 최솟값만큼 answer에 이어 붙인다.
            int commonCount = min(xCount, yCount);
            for(int i = 0; i < commonCount; i++) {
                answer += key;
            }
        }
    }
    
    // 4. answer의 길이가 0이면 "-1"을 반환한다.
    if(answer == "") return "-1";
    
    // 5. "00" 같은 형태로 존재하는 경우 "0" 하나만 반환한다.
    if(answer[0] == '0') return "0";
     
    return answer;
}
