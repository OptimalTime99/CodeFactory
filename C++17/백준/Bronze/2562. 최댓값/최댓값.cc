#include <iostream>

using namespace std;

int main()
{
    int N;
    int maxNumber = 0;
    int index = 0;
    
    for (int i = 0; i < 9; ++i)
    {
        cin >> N;
        
        if (N > maxNumber)
        {
            maxNumber = N;
            index = i;
        }
    }
    
    cout << maxNumber << "\n"
         << index + 1 << "\n";
    
    return 0;
}