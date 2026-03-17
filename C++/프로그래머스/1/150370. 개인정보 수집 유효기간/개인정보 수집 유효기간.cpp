#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 날짜 문자열(YYYY.MM.DD)을 '일(day)' 단위의 정수로 변환하는 함수
int convertToDays(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> termsMap;
    
    // 1. 오늘 날짜를 일(day) 단위로 변환
    int todayDays = convertToDays(today);
    
    // 2. terms의 개월 수를 일(day) 수로 변환하여 맵에 저장
    for (string term : terms) {
        termsMap[term[0]] = stoi(term.substr(2)) * 28; 
    }
    
    // 3. privacies 순회하며 파기해야 할 개인정보 찾기
    for (int i = 0; i < privacies.size(); i++) {
        string privacy = privacies[i];
        
        int collectedDays = convertToDays(privacy.substr(0, 10));
        
        char termType = privacy.back();
        
        int expireDays = collectedDays + termsMap[termType];
        
        if (todayDays >= expireDays) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}