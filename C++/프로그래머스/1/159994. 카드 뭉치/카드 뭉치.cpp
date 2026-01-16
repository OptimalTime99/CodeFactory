
// 1. goal의 단어를 순서대로 하나씩 확인한다.
// 2. cards1에서 가져올 수 있는지 확인하고 있으면 다음 카드로 넘어간다.
// 3. cards2에서 가져올 수 있는지 확인하고 있으면 다음 카드로 넘어간다.
// 4. 둘 다 카드가 없으면 매치가 안되므로 No를 반환한다.
// 5. 1~4를 통과했으면 Yes를 반환한다.
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // 각 카드 뭉치에서 현재 비교해야 할 위치(인덱스)
    int idx1 = 0;
    int idx2 = 0;
    
    // 1. goal의 단어를 순서대로 하나씩 확인한다.
    for(const string& target : goal)
    {
        // 2. cards1에서 가져올 수 있는지 확인하고 있으면 다음 카드로 넘어간다.
        if(idx1 < cards1.size() && cards1[idx1] == target)
        {
            idx1++;
        }
        // 3. cards2에서 가져올 수 있는지 확인하고 있으면 다음 카드로 넘어간다.
        else if(idx2 < cards2.size() && cards2[idx2] == target)
        {
            idx2++;
        }
        // 4. 둘 다 카드가 없으면 매치가 안되므로 No를 반환한다.
        else
        {
            return "No";
        }
    }
    
    // 5. 1~4를 통과했으면 Yes를 반환한다.
    return "Yes";
}