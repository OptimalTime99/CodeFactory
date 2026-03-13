#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void DFS(int V, vector<bool>& visited, vector<vector<int>>& graph)
{
    visited[V] = true;
    cout << V << " ";
    
    for (int u : graph[V])
    {
        if (!visited[u])
        {
            DFS(u, visited, graph);
        }
    }
}

void BFS(int V, vector<bool>& visited, vector<vector<int>>& graph)
{
       queue<int> Q;
       visited[V] = true;
       Q.push(V);
       
       while (!Q.empty())
       {
            int u = Q.front(); Q.pop();
            cout << u << " ";
            
            for (int w : graph[u])
            {
                if (!visited[w])
                {
                    visited[w] = true;
                    Q.push(w);
                }
            }
       }
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;
    
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);
    
    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;
        
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    DFS(V, visited, graph);
    cout << "\n";
    
    visited.assign(N + 1, false);
    BFS(V, visited, graph);

    return 0;
}