#include <iostream>

void hanoi(int n, int start, int via, int end)
{
    if (n == 0) return;
    
    hanoi(n - 1, start, end, via);
    std::cout << start << " " << end << "\n";
    hanoi(n - 1, via, start, end);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (!(std::cin >> n)) return 0;
    
    std::cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
    
    return 0;
}