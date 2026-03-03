#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(size_t t = 0; t < absolutes.size(); ++t)
    {
        if (!signs[t]) absolutes[t] *= -1;
        answer += absolutes[t];
    }
    
    return answer;
}