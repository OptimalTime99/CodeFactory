#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    
    cin >> N;
    
    for (int i = 0; i < N * N; ++i)
    {
        int num;
        cin >> num;
        
        pq.push(num);
        
        if (pq.size() > N)
        {
            pq.pop();
        }
    }
    
    cout << pq.top() << "\n";
    
    return 0;
}