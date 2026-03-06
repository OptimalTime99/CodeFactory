#include <iostream>
#include <map>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, M;
    std::cin >> N;
    
    // 오름차순 정렬이 자동으로 되는 map으로 입력받는 값들을 인덱스로 관리
    std::map<int ,int> countMap;
    for(int i = 0; i < N; ++i)
    {
        std::cin >> M;
        countMap[M]++;
    }
    
    // map에서 낮은 것부터 한줄씩 출력하기
    for(auto const& [key, val] : countMap)
    {
        for(int i = 0; i < val; ++i)
        {
            std::cout << key << "\n";
        }
    }
}