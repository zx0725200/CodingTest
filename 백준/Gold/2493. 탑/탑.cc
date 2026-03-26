#include <iostream>
#include <queue>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int StackNum;
    std::cin >> StackNum;
    
    std::stack<std::pair<int, int>> Stack;
    
    for (int i = 1; i <= StackNum; i++)
    {
        int InputNum;
        std::cin >> InputNum;
        
        while (!Stack.empty() && Stack.top().second < InputNum )
        {
            Stack.pop();
        }
        
        if (Stack.empty())
        {
            std::cout << "0 ";
        }
        else
        {
            std::cout << Stack.top().first << " ";
        }
        
        Stack.emplace(i, InputNum);
    }
    return 0;
}
