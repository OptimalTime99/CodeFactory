#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> elementSet;
    int elementSize = elements.size();
    
    // 원형 부분합 구하기 → 인덱스를 하나씩 옮겨가며 더하기
    for (int i = 0; i < elementSize; ++i)
    {
        int currentSum = 0;
        
        for (int j = 0; j < elementSize; ++j)
        {
            int nextIndex = (i + j) % elementSize;
            
            currentSum += elements[nextIndex];
            
            elementSet.insert(currentSum);
        }
    }
    
    return elementSet.size();
}