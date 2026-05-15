#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> counts;

    // 1. 빈도수 계산
    for (int size : tangerine) {
        counts[size]++;
    }

    // 2. 빈도수만 벡터에 추출
    vector<int> frequencies;
    for (auto const& [size, count] : counts) {
        frequencies.push_back(count);
    }

    // 3. 내림차순 정렬
    sort(frequencies.begin(), frequencies.end(), greater<int>());

    // 4. k가 0 이하가 될 때까지 가장 큰 빈도부터 차감
    for (int f : frequencies) {
        answer++;
        k -= f;
        if (k <= 0) break;
    }

    return answer;
}