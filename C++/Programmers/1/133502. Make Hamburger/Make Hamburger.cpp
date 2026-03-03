#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hamburgerMaker;

    // 불필요한 재할당을 막기 위해 메모리 미리 확보
    hamburgerMaker.reserve(ingredient.size()); 

    for (int i : ingredient) {
        hamburgerMaker.push_back(i);
        int size = hamburgerMaker.size();

        // 4개 이상이고, 마지막 재료가 빵(1)일 때만 검사
        if (size >= 4 && hamburgerMaker.back() == 1) { 
            if (hamburgerMaker[size - 4] == 1 && 
                hamburgerMaker[size - 3] == 2 && 
                hamburgerMaker[size - 2] == 3)
            {
                answer++;
                // pop_back 4번 대신 resize로 한 번에 처리
                hamburgerMaker.resize(size - 4); 
            }
        }
    }

    return answer;
}