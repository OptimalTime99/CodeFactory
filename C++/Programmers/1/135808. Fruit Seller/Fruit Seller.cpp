// k = 사과 하나의 최대 점수
// m = 한 상자에 담는 사과의 개수
// 과일 장수가 판매할 수 있는 상자 개수 = 사과의 전체 개수 / 한 상자에 담는 사과의 개수

// 1. 과일 장수가 판매할 수 있는 상자 개수 boxCount를 구한다.
// 2. 사과들의 점수인 score를 오름차순 정렬한다.
// 3. boxCount만큼 다음 과정을 반복한다.
// 4. m개만큼 score에서 내보낸다.
//    - 마지막으로 내보낸 값을 최저 사과 점수로 한다.
// 5. 최저 사과 점수 * m을 결과에 더한다.

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    // 1. 과일 장수가 판매할 수 있는 상자 개수 boxCount를 구한다.
    int boxCount = score.size() / m;
    
    // 2. 사과들의 점수인 score를 오름차순 정렬한다.
    sort(score.begin(), score.end());
    
    // 3. boxCount만큼 다음 과정을 반복한다.
    for(int i = 0; i < boxCount; ++i)
    {
        // 4. m개만큼 score에서 내보낸다.
        for(int j = 0; j < m; ++j)
        {
            // - 마지막으로 내보낸 값을 최저 사과 점수로 한다.
            if(j == m - 1)
            {
                int minAppleScore = score.back();
                
                // 5. 최저 사과 점수 * m을 결과에 더한다.
                answer += minAppleScore * m; 
            }
            
            score.pop_back();
        }
    }
    
    return answer;
}