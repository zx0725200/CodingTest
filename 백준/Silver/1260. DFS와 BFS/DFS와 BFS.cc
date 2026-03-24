#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

// 전역 변수
std::vector<std::vector<int>> graph;  
std::queue<int> MyRoot;
bool visited[1001];                    

void DFS(int Node)
{
    visited[Node] = true;
    
    printf("%d ", Node);
    
    for (int i = 0; i < graph[Node].size(); i++)
    {
        if (!visited[graph[Node][i]])
        {
            DFS(graph[Node][i]);
        }
    }
}


void BFS(int Node)
{
    visited[Node] = true;
    MyRoot.push(Node);
    
    while (!MyRoot.empty())
    {
        int NextNum = MyRoot.front();
        Node = NextNum;
        
        printf("%d ", NextNum);
        MyRoot.pop();
        
        for (int i = 0; i < graph[Node].size(); i++)
        {
            if (visited[graph[Node][i]])
            {
                continue;
            }
            
            visited[graph[Node][i]] = true;
            MyRoot.emplace(graph[Node][i]);
        }
    }
}

int main()
{
    int N, M, V;
    std::cin >> N >> M >> V;           

    graph.resize(N + 1);       

    for (int i = 0; i < M; i++)       
    {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);        
        graph[v].push_back(u);        
    }

    for (int i = 1; i <= N; i++)      
        std::sort(graph[i].begin(), graph[i].end());  

    DFS(V);
    printf("\n");                      
    
    memset(visited, false, sizeof(visited)); 
    
    BFS(V);
    printf("\n");

    return 0;
}