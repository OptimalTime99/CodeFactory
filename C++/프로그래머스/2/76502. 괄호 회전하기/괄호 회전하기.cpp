#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = 0;
    
    for (int i = 0; i < n; ++i)
    {
        vector<char> stack = {};
        bool isCorrect = true;
        
        for (int j = 0; j < n; ++j)
        {
            char c = s[(i + j) % n];
            
            if (c == '[' || c == '(' || c == '{') { stack.push_back(c); } 
            else {
                if (stack.size() == 0) { isCorrect = false; break; }
                
                char top = stack[stack.size() - 1];
                if (c == ']' && top == '[') { stack.pop_back(); } 
                else if (c == ')' && top == '(') { stack.pop_back(); } 
                else if (c == '}' && top == '{') { stack.pop_back(); } 
                else { isCorrect = false; break; }
            }
        }
        
        if (isCorrect && stack.size() == 0) { answer += 1; }
    }
    
    return answer;
}