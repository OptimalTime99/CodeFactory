#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    size_t size = a.size();
    
    for(size_t t = 0; t < size; ++t)
    {
        answer += a[t] * b[t];
    }
    
    return answer;
}