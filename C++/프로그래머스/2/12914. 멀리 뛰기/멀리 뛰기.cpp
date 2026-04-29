long long solution(int n) {
    if (n <= 2) return n;
    
    long long prev2 = 1;
    long long prev1 = 2;
    long long current = 0;
    
    for (int i = 3; i <= n; ++i)
    {
        current = (prev1 + prev2) % 1234567;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}





