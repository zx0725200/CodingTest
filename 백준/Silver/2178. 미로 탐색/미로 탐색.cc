#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::string> Graph(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> Graph[i];
    }
    
    std::queue<std::pair<int,int>> Result;
    
    int Visited[101][101];
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    memset(Visited, -1, sizeof(Visited)); 
    Visited[0][0] = 1;
    Result.emplace(0,0);
    
    while (!Result.empty())
    {
        int x = Result.front().first;   // 촌수의 ConnectNum 대신
        int y = Result.front().second;
        Result.pop();
        
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
        
            // 범위 밖이면 패스
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 불가능이면 패스
            if (Graph[nx][ny] == '0')
                continue;
            // 이미 방문이면 패스
            if (Visited[nx][ny] != -1)
                continue;
        
            Visited[nx][ny] = Visited[x][y] + 1;
            Result.emplace(nx, ny);
        }
    }
    
    printf("%d\n", Visited[N-1][M-1]); 
    
    return 0;
}