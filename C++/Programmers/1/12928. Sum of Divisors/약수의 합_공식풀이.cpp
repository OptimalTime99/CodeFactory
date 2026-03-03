long long solution(int n) {
    if (n <= 1) return n;
    
    long long ans = 1;
    int x = n;
    
    // 1) 소인수분해 (2부터 루트 x까지)
    for (long long p = 2; p * p <= x; ++p)
    {
        if (x % p != 0) continue;
        
        int a = 0;
        while (x % p == 0)
        {
            x /= (int)p;
            ++a;
        }
        
        // 2) 각 소수별 등비합 작성: 1 + p + ... + p^a
        long long term = 1;
        long long pk = 1;
        for (int i = 0; i < a; ++i)
        {
            pk *= p;
            term += pk;
        }
        
        // 3) 전부 곱
        ans *= term;
    }
    
    // 남은 소수가 있으면 지수 1
    if (x > 1)
    {
        ans *= (1LL + x);
    }
    
    return ans;
}
