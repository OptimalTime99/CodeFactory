#include <algorithm>
#include <string>

using namespace std;

bool compare(char a, char b)
{
    return a > b;
}


long long solution(long long n) {
    long long answer = 0;
    string strN = to_string(n);
    sort(strN.begin(), strN.end(), compare);
    answer = stoll(strN);
    
    return answer;
}