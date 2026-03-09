#include <iostream>
#include <algorithm>

int fibonacci(int n, int* memo)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    
    return memo[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    int size = 22; // +2는 추가 공간 확보
    
    int fibonacciNums[size];
    
    std::fill(fibonacciNums, fibonacciNums + size, -1);
    
    int fibonacciNum = fibonacci(n, fibonacciNums);
    std::cout << fibonacciNum;

    return 0;
}