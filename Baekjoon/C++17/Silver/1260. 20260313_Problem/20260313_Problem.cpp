#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int V, int N, vector<bool>& visited, const vector<vector<int>>& matrix)
{
    visited[V] = true;
    cout << V << " ";
    
    for (int i = 1; i <= N; ++i)
    {
        if (matrix[V][i] == 1 && !visited[i])
        {
            DFS(i, N, visited, matrix);
        }
    }
}

void BFS(int V, int N, vector<bool>& visited, const vector<vector<int>>& matrix)
{
    queue<int> Q;
    visited[V] = true;
    Q.push(V);
    
    while (!Q.empty())
    {
        int u = Q.front(); 
        Q.pop();
        cout << u << " ";
        
        for (int i = 1; i <= N; ++i)
        {
            if (matrix[u][i] == 1 && !visited[i])
            {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    vector<bool> visited(N + 1, false);
    
    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;
        
        matrix[start][end] = 1;
        matrix[end][start] = 1;
    }
   
    DFS(V, N, visited, matrix);
    cout << "\n";
    
    visited.assign(N + 1, false);
    
    BFS(V, N, visited, matrix);

    return 0;
}