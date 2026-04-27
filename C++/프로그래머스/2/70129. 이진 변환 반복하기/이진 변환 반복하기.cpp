#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n)
{
    if (n == 0) return "0";
    string result = "";
    while (n != 0)
    {
        result += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}
    

vector<int> solution(string s) {
    string result = s;
    int num = 0, count = 0;
    
    while (result != "1")
    {
        int length = result.length();
        int sum = 0;
        
        for (char c : result)
        {
            if (c == '1') ++sum;
        }
        
        count += (length - sum);
        result = toBinary(sum);
        ++num;
    }
    
    
    return {num, count};
}