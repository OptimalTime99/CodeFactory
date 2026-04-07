#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<int, vector<int>, greater<int>> minPq;
    
    int count;
    cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        int num;
        cin >> num;
        
        if (num == 0)
        {
            if (minPq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << minPq.top() << "\n";
                minPq.pop();
            }

        }
        else
        {
            minPq.push(num);
        }
    }
    
    return 0;
}