#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>

int main()
{
    int StackNum;
    std::cin >> StackNum;
    
    std::stack<int> Stack;
    
    int NextNum = 1;
    std::string Result;
    bool bFail = false;
    
    for (int i = 0; i < StackNum; i++)
    {
        int InputNum;
        std::cin >> InputNum;
        
        while (NextNum <= InputNum)
        {
            Stack.push(NextNum++);
            Result += "+\n";
        }
        
        if (Stack.top() == InputNum)
        {
            Stack.pop();
            Result += "-\n";
        }
        else
        {
            bFail = true;
            break;
        }
    }

    if (bFail)
        std::cout << "NO" << std::endl;
    else
        std::cout << Result;
    
    return 0;
}