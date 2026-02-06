#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {   
    // 1. 초기값을 제한사항 값인 50보다 큰 51로 설정한다.
    int minRow = 51, minCol = 51;
    int maxRow = 0, maxCol = 0;
    
    int rows = wallpaper.size();
    int cols = wallpaper[0].size();
    
    for (int rowIndex = 0; rowIndex < rows; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < cols; ++colIndex)
        {
            // 파일이 있는 칸(#)을 중심으로 점을 갱신한다.
            if (wallpaper[rowIndex][colIndex] == '#')
            {
                minRow = min(minRow, rowIndex);
                minCol = min(minCol, colIndex);
                maxRow = max(maxRow, rowIndex + 1);
                maxCol = max(maxCol, colIndex + 1);
            }
        }
    }
    
    return { minRow, minCol, maxRow, maxCol };
}