// n: 전체 벽 길이(meter)
// m: 롤러의 길이(meter)
// section: 1번부터 n번 사이의 칠해야 하는 벽 번호

// 1. m이 1인 경우 section의 크기 반환
// 2. section의 시작원소부터 m만큼 칠하고 다음 원소 탐색
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    // 1. m이 1인 경우 section의 크기 반환
    if(m == 1) return section.size();
    
    // 2. section의 시작원소부터 m만큼 칠하고 다음 원소 탐색
    int answer = 0;
    int cur_end = 0;
    
    for(int area : section)
    {
        if(area > cur_end)
        {
            ++answer;
            cur_end = area + m - 1;
        }
    }
    
    return answer;
}

