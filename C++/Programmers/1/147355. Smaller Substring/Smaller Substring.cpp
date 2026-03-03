#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLen = p.size();
    int tLen = t.size();
    
    long long pNum = stoll(p);

    for(int i = 0; i <= tLen - pLen; ++i)
    {
        string subStr = t.substr(i, pLen);
        
        if(stoll(subStr) <= pNum) {
            answer++;
        }
    }
    
    return answer;
}