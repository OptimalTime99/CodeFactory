#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- [전역 변수 및 설정] ---
const int MAX = 100005;
int n, m;
int arr[MAX];
vector<int> tree[MAX * 4];      // 병합 정렬 트리 (각 노드가 정렬된 벡터)
vector<int> sorted_vals;        // 좌표 압축 및 이중 이진 탐색을 위한 전체 정렬 배열

// --- [개념 1: 병합 정렬 트리 빌드 (Build)] ---
// 일반적인 병합 정렬의 'Merge' 단계를 트리 구조에 적용합니다.
void buildTree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].push_back(arr[start]);
        return;
    }

    int mid = (start + end) / 2;
    buildTree(node * 2, start, mid);
    buildTree(node * 2 + 1, mid + 1, end);

    // [중요] 자식 노드 2개를 합쳐서 부모 노드의 정렬된 벡터를 만듭니다. (O(N log N))
    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(tree[node * 2].begin(),     tree[node * 2].end(),
          tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
          tree[node].begin());
}

// --- [개념 2: 구간 내 개수 쿼리 (Query)] ---
// 구간 [left, right]에서 val보다 작거나 같은 숫자가 몇 개인지 세는 함수입니다.
int countLessEqual(int node, int start, int end, int left, int right, int val)
{
    // 1. 범위를 완전히 벗어난 경우 개수는 0
    if (left > end || right < start) return 0;

    // 2. 구간이 완전히 포함된 경우
    if (left <= start && end <= right)
    {
        // [중요] 노드 내부(정렬된 상태)에서 이진 탐색(upper_bound)으로 개수를 즉시 반환
        return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
    }

    // 3. 걸쳐 있는 경우 자식으로 내려가서 합산
    int mid = (start + end) / 2;
    return countLessEqual(node * 2, start, mid, left, right, val) +
           countLessEqual(node * 2 + 1, mid + 1, end, left, right, val);
}

// --- [개념 3: 매개변수 탐색 (Parametric Search)] ---
// "K번째 수"라는 정답을 찾기 위해 "X보다 작거나 같은 게 K개인가?"라는 질문을 반복합니다.
int findKthElement(int i, int j, int k)
{
    int low = 0, high = n - 1;
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int targetVal = sorted_vals[mid]; // 우리가 검사해볼 '값'

        // 쿼리 함수를 호출하여 구간 내에 targetVal 이하가 몇 개인지 확인
        if (countLessEqual(1, 1, n, i, j, targetVal) < k)
        {
            // k개보다 적다면 정답은 더 큰 값이어야 함
            low = mid + 1;
        } else {
            // k개 이상이라면 일단 정답 후보로 저장하고 더 작은 값도 확인
            result = targetVal;
            high = mid - 1;
        }
    }
    
    return result;
}

// --- [개념 4: 좌표 압축 및 초기화 (Preparation)] ---
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sorted_vals.push_back(arr[i]);
    }

    // [중요] 좌표 압축: 모든 숫자를 정렬해두어 이진 탐색의 '값 범위'를 인덱스로 관리
    sort(sorted_vals.begin(), sorted_vals.end());

    // 트리 생성
    buildTree(1, 1, n);

    // 쿼리 처리
    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        cout << findKthElement(i, j, k) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}