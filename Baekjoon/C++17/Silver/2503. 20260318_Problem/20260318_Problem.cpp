#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Query
{
    string baseballNumber;
    int strikes;
    int balls;
};

int numberBaseball(int N)
{
    vector<Query> queries(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> queries[i].baseballNumber
            >> queries[i].strikes
            >> queries[i].balls;
    }
    
    int possibleCount = 0;
    
    // 완전 탐색
    for (int i = 123; i <= 987; ++i)
    {
        string candidate = to_string(i);
        
        // 예외 처리
        if (candidate[0] == '0' || 
            candidate[1] == '0' || 
            candidate[2] == '0') continue;
        
        if (candidate[0] == candidate[1] || 
            candidate[1] == candidate[2] || 
            candidate[0] == candidate[2]) continue;
        
        bool isPossible = true;
        
        
        for (int j = 0; j < N; ++j)
        {
            int strikeCount = 0;
            int ballCount = 0;
            
            // 각 자리 수 비교
            for (int a = 0; a < 3; ++a)
            {
                for (int b = 0; b < 3; ++b)
                {
                    if (candidate[a] == queries[j].baseballNumber[b])
                    {
                        a == b ? ++strikeCount : ++ballCount;
                    }
                }
            }
            
            // 계산 결과와 다르다면 탈락
            if (strikeCount != queries[j].strikes ||
                  ballCount != queries[j].balls     )
            {
                isPossible = false;
                break;
            }
        }
        
        // 가능한 숫자 체크
        if (isPossible) ++possibleCount;
    }
    
    return possibleCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int possibleCount = numberBaseball(N);
    cout << possibleCount;
    
    return 0;
}