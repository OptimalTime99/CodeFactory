#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    // 1. 성격 유형별 점수 저장 (쉼표로 초기화)
    map<char, int> scores = {
        {'R', 0}, {'T', 0},
        {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0},
        {'A', 0}, {'N', 0}
    };
    
    // 2. 검사 결과 집계
    for (int i = 0; i < survey.size(); ++i) {
        int choice = choices[i];
        
        if (choice < 4) {
            // 비동의 -> 첫 번째 캐릭터
            scores[survey[i][0]] += (4 - choice);
        } else if (choice > 4) {
            // 동의 -> 두 번째 캐릭터
            scores[survey[i][1]] += (choice - 4);
        }
    }
    
    // 3. 지표별로 비교하여 결과 생성
    // 점수가 같으면 사전 순(코드에 명시된 순서)으로 처리하도록 구성
    answer += (scores['R'] >= scores['T']) ? 'R' : 'T';
    answer += (scores['C'] >= scores['F']) ? 'C' : 'F';
    answer += (scores['J'] >= scores['M']) ? 'J' : 'M';
    answer += (scores['A'] >= scores['N']) ? 'A' : 'N';
    
    return answer;
}