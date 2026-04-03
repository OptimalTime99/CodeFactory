#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // 당한 사람 -> {신고자1, 신고자2, ...} (중복 제거)
    unordered_map<string, unordered_set<string>> nameList;
    
    // 신고자 -> 받을 메일 수
    unordered_map<string, int> nameMap;
    vector<int> answer;
    
    // 1. 공백을 기준으로 신고자, 당한 사람 나누고 nameList에 넣기
    for (string str : report) {
        stringstream ss(str);
        string reporter, reported;
        ss >> reporter >> reported;
        
        // set의 특성상 중복된 reporter는 알아서 무시됨
        nameList[reported].insert(reporter); 
    }
    
    // 2. 정지 기준을 만족하는지 확인하고, 신고자에게 메일 발송 카운트 올리기
    for (auto& names : nameList) {
        // names.first: 당한 사람
        // names.second: 신고자들의 set
        
        if (names.second.size() >= k) { // k번 이상 신고당했다면 정지
            // 해당 유저를 신고한 모든 사람의 메일 카운트 1 증가
            for (string reporter : names.second) {
                nameMap[reporter]++;
            }
        }
    }
    
    // 3. id_list 순서대로 answer 배열에 메일 받는 횟수 넣기
    for (string id : id_list) {
        answer.push_back(nameMap[id]);
    }
    
    return answer;
}