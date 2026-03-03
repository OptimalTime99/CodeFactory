int solution(int n) {
    int answer = 0;

    // 모든 자연수를 1로 나눌 때는 나머지가 없기 때문에
    // 2부터 n까지 반복하면서 n % x == 1 이 있는지 확인
    for (int x = 2; x <= n; ++x)
    {
        if (n % x == 1)
        {
            answer = x;
            break;
        }
    }
    
    return answer;
}
