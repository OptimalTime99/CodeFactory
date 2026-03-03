void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

long long solution(int a, int b) {
    if (a == b) return a;
    if(a > b) swap(a, b);
    
    long long answer = 0;
    
    for(int i = a; i <= b; ++i)
    {
        answer += i;
    }
    
    return answer;
}