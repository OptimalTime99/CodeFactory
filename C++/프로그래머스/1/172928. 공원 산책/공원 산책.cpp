#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> values;
    int rowSize = park[0].size();
    int colSize = park.size();
    int totalSize = rowSize * colSize;
    int currentIndex = 0;
    
    // 1. 공원을 1차원 배열로 변환 및 시작 위치 찾기
    for (int r = 0; r < colSize; ++r) {
        for (int c = 0; c < rowSize; ++c) {
            char cell = park[r][c];
            if (cell == 'S') {
                values.push_back(2);
                currentIndex = values.size() - 1;
            } else if (cell == 'O') {
                values.push_back(1);
            } else if (cell == 'X') {
                values.push_back(0);
            }
        }
    }
    
    // 2. 이동 명령 수행
    for (string route : routes) {
        char direction = route[0];
        int move = route[2] - '0';
        
        bool canMove = true;
        int nextIndex = currentIndex;
        
        for (int step = 1; step <= move; ++step) {
            if (direction == 'N') {
                nextIndex -= rowSize;
            } else if (direction == 'S') {
                nextIndex += rowSize;
            } else if (direction == 'W') {
                // 서쪽 이동 시, 맨 왼쪽 열(0번째 열)에서 왼쪽으로 가려고 하면 실패
                if (nextIndex % rowSize == 0) { canMove = false; break; }
                nextIndex -= 1;
            } else if (direction == 'E') {
                // 동쪽 이동 시, 맨 오른쪽 열(rowSize-1 번째 열)에서 오른쪽으로 가려고 하면 실패
                if (nextIndex % rowSize == rowSize - 1) { canMove = false; break; }
                nextIndex += 1;
            }
            
            // 맵 전체를 벗어났는지 확인 (N, S 이동 시 중요)
            if (nextIndex < 0 || nextIndex >= totalSize) {
                canMove = false;
                break;
            }
            
            // 장애물(X)이 있는지 확인 (0은 X를 의미)
            if (values[nextIndex] == 0) {
                canMove = false;
                break;
            }
        }
        
        // 이동이 무사히 가능하다면 현재 위치 업데이트
        if (canMove) {
            currentIndex = nextIndex;
        }
    }
    
    // 3. 1차원 인덱스를 다시 2차원 좌표(행, 열)로 변환하여 반환
    vector<int> answer;
    answer.push_back(currentIndex / rowSize); // 행(Row) 좌표
    answer.push_back(currentIndex % rowSize); // 열(Column) 좌표
    
    return answer;
}