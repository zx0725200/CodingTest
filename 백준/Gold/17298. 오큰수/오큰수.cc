#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int StackNum;
    std::cin >> StackNum;
    
    std::stack<std::pair<int,int>> Stack;
    std::vector<int> SaveList(StackNum + 1, -1);
    
    for (int i = 1; i <= StackNum; i++)
    {
        int InputNum;
        std::cin >> InputNum;
        
        while (!Stack.empty() && Stack.top().second < InputNum)
        {
            SaveList[Stack.top().first] = InputNum;  // 인덱스 위치에 저장
            Stack.pop();
        }
        
        Stack.emplace(i, InputNum);
    }
    
    for (int i = 1; i <= StackNum; i++)
    {
        std::cout << SaveList[i] << " ";
    }
    
    
    return 0;
}
