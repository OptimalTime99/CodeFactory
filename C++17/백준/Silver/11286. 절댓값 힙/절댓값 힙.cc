#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Compare
{
    bool operator()(const int a, const int b)
    {
        if (abs(a) != abs(b))
        {
            return abs(a) > abs(b);
        }
        else
        {
            return a > b;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<int, vector<int>, Compare> minAbsPq;
    
    int count;
    cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        int num;
        cin >> num;
        
        if (num == 0)
        {
            if (minAbsPq.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << minAbsPq.top() << "\n";
                minAbsPq.pop();
            }

        }
        else
        {
            minAbsPq.push(num);
        }
    }
    
    return 0;
}