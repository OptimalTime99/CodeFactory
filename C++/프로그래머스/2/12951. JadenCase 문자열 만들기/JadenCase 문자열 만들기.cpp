#include <string>

using namespace std;

string solution(string s) {
    bool isNewWord = true;
    
    for (int i = 0; i <s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            isNewWord = true;
        } 
        
        else if (isNewWord)
        {
            if (isalpha(s[i]))
            {
                s[i] = toupper(s[i]);
            }
            
            isNewWord = false;
        } 
        
        else
        {
            s[i] = tolower(s[i]);
        }
    }
    
    return s;
}