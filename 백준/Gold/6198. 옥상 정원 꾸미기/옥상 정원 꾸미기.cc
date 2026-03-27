#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int StackNum;
    std::cin >> StackNum;
    
    std::stack<int> Stack;
    long Count = 0; 
    
    for (int i = 1; i <= StackNum; i++)
    {
        int InputNum;
        std::cin >> InputNum;
        
        while (!Stack.empty() && Stack.top() <= InputNum )
        {
            Stack.pop();
        }
        
        Count += Stack.size();
        Stack.emplace(InputNum);
    }
    
    printf("%ld",Count);
    return 0;
}
