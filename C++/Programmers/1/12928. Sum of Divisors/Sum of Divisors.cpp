long long solution(int n)
{
    long long ans = 0;
    for (long long d = 1; d * d <= n; ++d)
    {
        if (n % d) continue;
        
        long long q = n / d;
        ans += d;
        if(q != d) ans += q;
    }
    
    return ans;
}
