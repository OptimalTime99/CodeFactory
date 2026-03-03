#include <vector>
#include <queue> 

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    // 오름차순 우선순위 큐 (작은 숫자가 위로 옴 == Min Heap)
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int sco : score) {
        pq.push(sco); // 점수 추가 (자동 정렬됨)
        
        // 명예의 전당이 꽉 찼다면
        if (pq.size() > k) {
            pq.pop(); // 가장 작은 점수(top)를 버림
        }
        
        // 남은 것 중 가장 작은 점수가 명예의 전당 턱걸이 점수
        answer.push_back(pq.top());
    }
    
    return answer;
}
