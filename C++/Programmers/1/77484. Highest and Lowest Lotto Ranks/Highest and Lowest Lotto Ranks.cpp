// 1. lottos의 모든 값이 0이라면 result는 [1, 6] 반환한다.
// 2. lottos가 win_nums에 일치하는게 몇개인지 확인한다.
// - lottos의 원소가 0이 아니라면 win_nums의 원소와 비교: 최저 순위 구하기
// - lottos의 원소가 0이라면 0 개수로 카운트
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // 1. lottos의 모든 값이 0이라면 result는 [1, 6] 반환한다.
    if (all_of(lottos.begin(), lottos.end(), [](int n){return n == 0;})) return {1, 6};
    
    int place = 7;
    int zeroCount = 0;
    // 2. lottos가 win_nums에 일치하는게 몇개인지 확인한다.
    for(int i = 0; i < 6; ++i)
    {
        int current = lottos[i];
        // - lottos의 원소가 0이 아니라면 win_nums의 원소와 비교: 최저 순위 구하기
        if(current != 0)
        {
            if(find(win_nums.begin(), win_nums.end(), current) != win_nums.end())
            {
                --place;
            }
        }
        // - lottos의 원소가 0이라면 0 개수로 카운트
        else
        {
            ++zeroCount;
        }
    }
    
    if(place == 7) place = 6;
    
    return {place - zeroCount, place};
}