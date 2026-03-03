#include <string>

using namespace std;

string solution(string phone_number) {
    const int LAST_DIGITS = 4;
    
    for(int i = 0; i < phone_number.length() - LAST_DIGITS; ++i)
    {
        phone_number[i] = '*';
    }
    
    return phone_number;
}