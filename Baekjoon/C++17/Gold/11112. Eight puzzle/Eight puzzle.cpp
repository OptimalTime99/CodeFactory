#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// 목표 상태
const string TARGET = "12345678#";

// 노드 구조체
struct Node {
    string state;
    int emptyIdx;
    int g, h, f;

    // Min-Heap (f값이 작은 것 우선, 같다면 g가 큰 것 우선)
    bool operator>(const Node& other) const {
        if (f == other.f) {
            return g > other.g; 
        }
        return f > other.f;
    }
};

// 휴리스틱 함수 (맨해튼 거리의 합)
int GetHeuristic(const string& state) {
    int h = 0;
    for (int i = 0; i < 9; ++i) {
        if (state[i] == '#') continue;
        
        int tileNumber = state[i] - '0';
        int currentY = i / 3, currentX = i % 3;
        int targetY = (tileNumber - 1) / 3, targetX = (tileNumber - 1) % 3;
        
        h += abs(currentY - targetY) + abs(currentX - targetX);
    }
    return h;
}

// 도달 불가능 케이스를 수학적으로 사전 차단하는 함수
bool IsSolvable(const string& state) {
    int inversions = 0;
    string temp = "";
    
    // 빈칸('#')을 제외한 순수 숫자 배열 생성
    for (char c : state) {
        if (c != '#') temp += c;
    }
    
    // Inversion Count (자신보다 뒤에 있는 작은 숫자의 개수) 측정
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            if (temp[i] > temp[j]) inversions++;
        }
    }
    
    // 3x3 퍼즐에서 Inversion Count가 짝수여야만 해답에 도달 가능
    return inversions % 2 == 0;
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// A* 알고리즘 메인 탐색
int AStarSearch(const string& startState) {
    // 시작점이 이미 정답인 경우 예외 처리
    if (startState == TARGET) return 0;

    priority_queue<Node, vector<Node>, greater<Node>> openList;
    unordered_set<string> closedList;

    int startEmptyIdx = startState.find('#');
    int startH = GetHeuristic(startState);
    
    openList.push({startState, startEmptyIdx, 0, startH, startH});
    closedList.insert(startState); // 시작 노드 방문 처리

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.state == TARGET) {
            return current.g;
        }

        int cy = current.emptyIdx / 3;
        int cx = current.emptyIdx % 3;

        for (int i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3) {
                int nextEmptyIdx = ny * 3 + nx; 
                
                string nextState = current.state;
                swap(nextState[current.emptyIdx], nextState[nextEmptyIdx]);

                // Set을 활용한 O(1) 방문 확인
                if (closedList.find(nextState) == closedList.end()) {
                    closedList.insert(nextState); // 큐에 넣을 때 방문 처리하여 중복 삽입 방지
                    int newG = current.g + 1;
                    int newH = GetHeuristic(nextState);
                    openList.push({nextState, nextEmptyIdx, newG, newH, newG + newH});
                }
            }
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string startState = "";
        // 3줄에 걸쳐 주어지는 보드판을 하나의 문자열로 결합
        for (int i = 0; i < 3; ++i) {
            string row;
            cin >> row;
            startState += row;
        }

        // 1. 수학적으로 풀 수 없는 퍼즐인지 먼저 검증 (시간 초과 방지)
        if (!IsSolvable(startState)) {
            cout << "impossible\n";
            continue;
        }

        // 2. 풀 수 있는 퍼즐만 A* 알고리즘 실행
        int result = AStarSearch(startState);
        
        if (result == -1) cout << "impossible\n";
        else cout << result << "\n";
    }

    return 0;
}