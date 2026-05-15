#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> tangerineMap;

    // 1. 빈도수 계산
    for (int size : tangerine) {
        tangerineMap[size]++;
    }

    // 2. {빈도수, 귤크기} 쌍으로 저장하여 정렬
    vector<pair<int, int>> v;
    for(auto& it : tangerineMap) {
        v.push_back({it.second, it.first});
    }

    // 3. 내림차순 정렬
    sort(v.rbegin(), v.rend());

    // 4. k가 0 이하가 될 때까지 가장 큰 빈도부터 차감
    for (auto const& [key, value] : v) {
        answer++;
        k -= key;
        if (k <= 0) break;
    }

    return answer;
}