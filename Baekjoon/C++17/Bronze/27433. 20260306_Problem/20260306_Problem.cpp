#include <iostream>

long long fact(long long N)
{
    if(N <= 1) return 1;
    return N * fact(N - 1);
}

int main()
{
    long long N;
    std::cin >> N;
    std::cout << fact(N);
    
    return 0;
}