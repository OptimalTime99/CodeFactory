#include <iostream>

int N, K;
int cnt = 0;
int answer = -1;
int tmp[500001];

// 병합하는 함수
void merge(int A[], int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = 0;
    
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    
    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];
    
    i = p;
    t = 0;
    while (i <= r)
    {
        A[i] = tmp[t++];
        cnt++;
        
        if (cnt == K) answer = A[i];
        i++;
    }
}

// 분할하는 함수
void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> N >> K;
    
    int* arr = new int[N];
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }
    
    merge_sort(arr, 0, N - 1);
    
    std::cout << answer;
    
    delete[] arr;
    
    return 0;
}