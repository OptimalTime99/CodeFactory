#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    
    istringstream iss(s);
    string token;
    vector<int> numbers;
    
    while (iss >> token)
    {
        int num = stoi(token);
        numbers.push_back(num);
    }
    
    string answer = "";
    
    auto [minVal, maxVal] = minmax_element(numbers.begin(), numbers.end());

    answer = to_string(*minVal) + " " + to_string(*maxVal);
    
    return answer;
}