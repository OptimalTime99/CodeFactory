#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int H = park.size();      // 공원의 세로 길이 (행)
    int W = park[0].size();   // 공원의 가로 길이 (열)
    int y = 0, x = 0;         // 현재 위치 (행, 열)
    
    // 1. 공원에서 시작 위치(S) 찾기
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (park[i][j] == 'S') {
                y = i;
                x = j;
            }
        }
    }
    
    // 2. 방향 벡터 설정: 북(N), 남(S), 서(W), 동(E) 순서
    // 인덱스: 0(N), 1(S), 2(W), 3(E)
    int dy[] = {-1, 1, 0, 0}; // y좌표 (행) 변화량
    int dx[] = {0, 0, -1, 1}; // x좌표 (열) 변화량
    
    // 3. 이동 명령 수행
    for (string route : routes) {
        char op = route[0];           // 이동 방향
        int n = route[2] - '0';       // 이동 횟수
        
        // 방향에 맞는 인덱스 찾기
        int dir = -1;
        if (op == 'N') dir = 0;
        else if (op == 'S') dir = 1;
        else if (op == 'W') dir = 2;
        else if (op == 'E') dir = 3;
        
        int ny = y; // 이동을 시뮬레이션 해볼 임시 y
        int nx = x; // 이동을 시뮬레이션 해볼 임시 x
        bool canMove = true;
        
        // n칸만큼 한 칸씩 전진하며 검사
        for (int step = 0; step < n; ++step) {
            ny += dy[dir];
            nx += dx[dir];
            
            // 조건 1: 공원 밖을 벗어나는지 확인
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                canMove = false;
                break;
            }
            // 조건 2: 장애물(X)을 만나는지 확인
            if (park[ny][nx] == 'X') {
                canMove = false;
                break;
            }
        }
        
        // 중간에 장애물을 만나거나 맵을 벗어나지 않았다면, 실제 위치를 업데이트
        if (canMove) {
            y = ny;
            x = nx;
        }
    }
    
    return {y, x};
}
