// 명예의 전당: 내림차순 정렬되는 배열으로, pop 연산이 편한걸로 구성
// 반환값: 명예의 전당 최하위 점수가 있는 score 길이의 벡터 

// [의사코드 작성]
// 1. 명예의 전당 벡터를 미리 k 크기만큼 -1로 초기화한다.
// 2. 새로운 점수가 들어오면 명예의 전당 말석과 비교한다.
// 3. 새 점수가 더 크다면 말석을 내보낸다.
// 4. 처음부터 순회하며 들어갈 자리를 찾는다.
// 5. 명예의 전당 점수를 내림차순 정렬한다.
// 6. 매일 명예의 전당 최하위 점수를 결과에 더한다.

// [개선된 의사코드]
// 1. 점수를 명예의 전당에 넣는다.
// 2. 명예의 전당을 내림차순으로 정렬한다.
// 3. 만약 명예의 전당 정원을 초과했다면? -> 말석을 탈락시킨다.
// 4. 현재 명예의 전당의 최하위 점수를 결과에 저장한다.

// [의사코드 풀이]
// #include <algorithm>
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(int k, vector<int> score) {
//     vector<int> answer;
    
//     // 1. 명예의 전당 벡터를 미리 k 크기만큼 -1로 초기화한다.
//     vector<int> honor(k, -1);
    
//     for(int sco : score)
//     {
//         // 2. 새로운 점수가 들어오면 명예의 전당 말석(최하위)과 비교한다.
//         if(sco > honor[honor.size() - 1])
//         {
//             // 3. 새 점수가 더 크다면 말석을 내보낸다
//             honor.pop_back();
            
//             // 4. 처음부터 순회하며 들어갈 자리를 찾는다.
            
//         }
        
//         // 5. 명예의 전당 점수를 내림차순 정렬한다.
//         sort(honor.begin(), honor.end(), greater<int>());
        
//         // 6. 매일 명예의 전당 최하위 점수를 결과에 더한다.
//         answer.push_back(honor[honor.size() - 1]);
//     }
    
//     return answer;
// }

// [개선된 의사코드 풀이]
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honor; // 초기 크기 지정 없이 빈 벡터로 시작
    
    for(int sco : score)
    {
        // 1. 점수를 명예의 전당에 넣는다.
        honor.push_back(sco);
        
        // 2. 명예의 전당을 내림차순 정렬합니다.
        sort(honor.begin(), honor.end(), greater<int>());
        
        // 3. 만약 명예의 전당 정원을 초과했다면?
        if(honor.size() > k)
        {
            // 말석을 탈락시킨다.
            honor.pop_back();
        }
        
        // 4. 현재 명예의 전당의 최하위 점수를 결과에 저장한다.
        answer.push_back(honor.back());
    }
    
    return answer;
}