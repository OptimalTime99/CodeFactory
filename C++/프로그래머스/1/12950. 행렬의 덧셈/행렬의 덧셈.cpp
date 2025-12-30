#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rowSize = arr1.size();
    vector<vector<int>> answer(rowSize);
    
    for(int i = 0; i < rowSize; ++i)
    {
        int colSize = arr1[i].size();
        for(int j = 0; j < colSize; ++j)
        {
            int sum = arr1[i][j] + arr2[i][j];
            answer[i].push_back(sum);
        }
    }
    
    return answer;
}
