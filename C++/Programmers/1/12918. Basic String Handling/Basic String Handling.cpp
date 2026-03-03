#include <string>

using namespace std;

bool solution(string s) {
    size_t size = s.size();
    
    if(size != 4 && size != 6) return false;
    
    for(char c : s)
    {
        if (c - '9' > 0) return false;
    }
    
    return true;
}