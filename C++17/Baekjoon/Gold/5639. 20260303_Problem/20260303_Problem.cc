#include <iostream>
#include <vector>

std::vector<int> tree;

void postOrder(int start, int end)
{
    int root = tree[start];
    int idx = start + 1;
    
    if (start >= end)
    {
        if (start == end)
        {
            std::cout << root << "\n";
        }
        
        return;
    }
    
    // 오른쪽 서브트리의 시작 지점 찾기
    while (idx <= end)
    {
        if (tree[idx] > root) break;
        idx++;
    }
    
    // 왼쪽 서브트리 방문
    postOrder(start + 1, idx - 1);
    // 오른쪽 서브트리 방문
    postOrder(idx, end);
    // 루트 출력
    std::cout << root << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    while (std::cin >> n)
    {
        tree.push_back(n);
    }
    
    if (!tree.empty())
    {
        postOrder(0, tree.size() - 1);
    }
    
    return 0;
}