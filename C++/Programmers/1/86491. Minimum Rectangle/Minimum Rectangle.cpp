/*
1. 명함을 눕히든 세우든 상관없이, 긴 쪽을 무조건 가로로, 짧은 쪽을 무조건 세로로 정렬한다.
2. 모든 명함에 대해 가장 큰 가로, 세로 값을 갱신한다.
   - 다양한 크기의 명함들을 모두 수납할 수 있기 위함
3. 1~2번 과정을 통한 최대 가로, 최대 세로 값을 곱해 적절한 명함의 크기를 구한다.
   - 작은 것부터 큰 방향으로 가 모든 조건을 만족하면서 그 중에서 가장 작은 크기의 값을 구함.
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;
    
    for (const auto& card : sizes)
    {
        // 1. 명함을 눕히든 세우든 상관없이, 긴 쪽을 무조건 가로로, 짧은 쪽을 무조건 세로로 정렬한다.
        int w = max(card[0], card[1]);
        int h = min(card[0], card[1]);
        
        // 2. 모든 명함에 대해 가장 큰 가로, 세로 값을 갱신한다.
        if (w > max_w) max_w = w;
        if (h > max_h) max_h = h;
    }
    
    // 3. 1~2번 과정을 통한 최대 가로, 최대 세로 값을 곱해 적절한 명함의 크기를 구한다.
    return max_w * max_h;
}


