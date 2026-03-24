#include <iostream>
#include <queue>
#include <vector>



std::vector<std::vector<int>> Graph;
std::queue<int> Result;
bool Visited[101];

void PrintResult()
{
    int ResultCount = 0;
    int VirusComputer = 1;
    Visited[VirusComputer] = true;
    Result.emplace(VirusComputer);
    
    while (!Result.empty())
    {
        int ConnectNum = Result.front();
        Result.pop();
        
        for (int i = 0; i < Graph[ConnectNum].size(); i++)
        {
            if (Visited[Graph[ConnectNum][i]])
            {
                continue;
            }
            
            ResultCount++;
            
            Visited[Graph[ConnectNum][i]] = true;
            Result.emplace(Graph[ConnectNum][i]);
        }
    }
    
    printf("%d\n", ResultCount);
}

int main()
{
    int ComputerTotalNum = 0;
    int ConnectTotalNum = 0;
    
    std::cin >> ComputerTotalNum;
    std::cin >> ConnectTotalNum;
    
    Graph.resize(ComputerTotalNum + 1);   
    
    for (int i = 0; i < ConnectTotalNum; i++)
    {
        int FirstComputer;
        int SecondComputer;
        
        std::cin >> FirstComputer >> SecondComputer;
        
        Graph[FirstComputer].push_back(SecondComputer);        
        Graph[SecondComputer].push_back(FirstComputer);
    }
    
    PrintResult();
    
    return 0;
}