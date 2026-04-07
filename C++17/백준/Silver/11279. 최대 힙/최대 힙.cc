#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<int> pq;
    
    int count;
    cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        int num;
        cin >> num;
        
        if (num == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }

        }
        else
        {
            pq.push(num);
        }
    }
    
    return 0;
}