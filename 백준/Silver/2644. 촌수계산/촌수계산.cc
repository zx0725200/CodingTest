#include <iostream>
#include <queue>
#include <vector>
#include <cstring>


std::vector<std::vector<int>> Graph;
std::queue<int> Result;
int Visited[101];
int ResultCount;

void PrintResult(int FirstNum, int SecondNum)
{
    memset(Visited, -1, sizeof(Visited)); 
    
    Visited[FirstNum] = 0;
    Result.emplace(FirstNum);
    
    while (!Result.empty())
    {
        int ConnectNum = Result.front();
        Result.pop();
        
        for (int i = 0; i < Graph[ConnectNum].size(); i++)
        {
            int Next = Graph[ConnectNum][i];
         
            // 이미 지정된 애들 제외.
            if (Visited[Next] != -1)
            {
                continue;
            }
            
            Visited[Next] = Visited[ConnectNum] + 1;
            
            if (Next == SecondNum)
            {
                printf("%d\n", Visited[Next]);
                return;
            }
            
            Result.emplace(Next);
        }
    }
    
    printf("%d\n", -1);
}

int main()
{
    int TotalNum = 0;
    
    std::cin >> TotalNum;
    Graph.resize(TotalNum + 1);
    
    int FirstNum;
    int SecondNum;
    
    std::cin >> FirstNum >> SecondNum;
    int ConnectNum = 0;
    std::cin >> ConnectNum;
    
    for (int i = 0; i < ConnectNum; i++)
    {
        int ConnectFirst;
        int ConnectSecond;
        
        std::cin >> ConnectFirst >> ConnectSecond;
        
        Graph[ConnectFirst].push_back(ConnectSecond);        
        Graph[ConnectSecond].push_back(ConnectFirst);
    }
    
    PrintResult(FirstNum, SecondNum);
    
    return 0;
}