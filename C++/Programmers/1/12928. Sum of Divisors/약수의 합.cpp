int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        int remain = n / i;
        
        if (n == remain * i)
        {
            answer += remain;
        }
    }
    
    return answer;
}