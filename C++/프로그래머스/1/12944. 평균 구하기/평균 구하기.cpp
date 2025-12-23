#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int number : arr)
    {
        answer += number;
    }
    
    answer /= arr.size();
    
    return answer;
}