// 1. 일요일부터 토요일까지 담은 요일 맵을 초기화한다.
// 2. 일, 월, 연도를 각 변수로 설정한다.
// 3. 1월, 2월은 전년도 13월, 14월로 변경한다.
// 4. 첼러의 공식에 대입해 계산한다.
// 5. 음수 모듈러 처리
// 6. 결과로 나온 숫자를 요일 맵에 대조해 결과를 구한다.
#include <map>
#include <string>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    // 1. 일요일부터 토요일까지 담은 요일 맵을 초기화한다.
    map<int, string> dayMap = {
        {0, "SAT"},
        {1, "SUN"},
        {2, "MON"},
        {3, "TUE"},
        {4, "WED"},
        {5, "THU"},
        {6, "FRI"}
    };
    
    // 2. 일, 월, 연도를 각 변수로 설정한다.
    int q = b;
    int m = a;
    int year = 2016;
    
    // 3. 1월, 2월은 전년도 13월, 14월로 변경한다.
    if(m < 3)
    {
        m += 12;
        year -= 1;
    }
    
    int K = year % 100;
    int J = year / 100;
    
    
    // 4. 첼러의 공식에 대입해 계산한다.
    int calcValue = (q + ((13 * (m + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    // 5. 음수 모듈러 처리
    if(calcValue < 0)
    {
        calcValue += 7;
    }
    
    // 6. 결과로 나온 숫자를 요일 맵에 대조해 결과를 구한다.
    answer = dayMap[calcValue];
    
    return answer;
}