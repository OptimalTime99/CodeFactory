#include <string>
#include <map>
#include <cctype> // isdigit, isalpha

using namespace std;

// 1. 숫자 영단어 대응 표를 만든다.
// 2. 문자열을 순회한다.
// 2-1. 현재 문자가 숫자이면, 그대로 결과에 숫자를 넣는다.
// 2-2. 현재 문자가 문자이면, 변수 str에 넣고 str과 대응 표와 비교한다.
// 2-2-1. 대응 표와 str이 같다면 결과에 해당되는 숫자를 넣고, str을 비운다.
int solution(string s) {
    string answer = "";
    
    // 1. 숫자 영단어 대응 표를 만든다.
    map<string, char> numberMap = {
        {"zero", '0'},
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };
    
    string str = "";
    
    // 2. 문자열을 순회한다.
    for(char c : s)
    {
        // 2-1. 현재 문자가 숫자이면, 그대로 결과에 숫자를 넣는다.
        if(isdigit(c)) answer+= c;
        
        // 2-2. 현재 문자가 문자이면, 변수 str에 넣고 str과 대응 표와 비교한다.
        else {
            str += c;
            
            // 2-2-1. 대응 표와 str이 같다면 결과에 해당되는 숫자를 넣고, str을 비운다.
            if(numberMap.find(str) != numberMap.end())
            {
                answer += numberMap[str];
                
                str = "";
            }
        }
    }
    
    return stoi(answer);
}