#include <string>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    string str = to_string(x);
    
    for(size_t t = 0; t < str.size(); ++t)
    {
        sum += str[t] - '0';
    }
    
    if(x % sum != 0) answer = false;
    
    return answer;
}