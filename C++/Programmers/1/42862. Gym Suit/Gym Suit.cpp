#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // 1. 전체 학생을 배열로 받는다.
    // 각 원소는 다음과 같이 저장한다.
    // - 체육복이 있는 학생은 1
    vector<int> totalStudent(n, 1);
    
    // - 여벌 체육복까지 있는 학생은 +1
    for (int two : reserve)
    {
        ++totalStudent[two - 1];
    }
    
    // - 체육복을 도난당한 학생은 -1
    for (int zero : lost)
    {
        --totalStudent[zero - 1];
    }
    
    // 2. 전체 학생을 순회하며 체육복을 도난당한 학생이 있다면,
    const int TOTAL_STUDENT_SIZE = totalStudent.size();
    int lostCount = 0;
    for (int i = 0; i < TOTAL_STUDENT_SIZE; ++i)
    {
        if(totalStudent[i] == 0)
        {
            // - 앞 번호가 여벌 체육복이 있다면 나눠 받는다.
            if(totalStudent[i - 1] == 2)
            {
                totalStudent[i - 1] = 1;
                totalStudent[i] = 1;
                continue;
            }
            
            // - 뒷 번호가 여벌 체육복이 있다면 나눠 받는다.
            else if(totalStudent[i + 1] == 2)
            {
                totalStudent[i + 1] = 1;
                totalStudent[i] = 1;
                continue;
            }
            
            // - 빌릴 체육복이 없어 수업을 듣지 못하는 학생 수를 체크한다.
            else
            {
                ++lostCount;
            }
        }
    }
    
    // 3. 원소값이 0인 원소를 찾아 전체 학생 수에서 뺀다.
    answer = TOTAL_STUDENT_SIZE - lostCount;
    
    return answer;
}