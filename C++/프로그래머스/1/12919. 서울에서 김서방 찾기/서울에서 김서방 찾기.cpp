#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    for(size_t t = 0; t < seoul.size(); ++t)
    {
        if (seoul[t] == "Kim") 
        {
            answer = "김서방은 " + to_string(t) + "에 있다";
        }
    }
    
    return answer;
}