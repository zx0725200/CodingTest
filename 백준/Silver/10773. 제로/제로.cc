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
    for (int i = 0; i < StackNum; i++)
    {
        int Input;
        std::cin >> Input;
        
        if (Input == 0)
        {
            Stack.pop();
        }
        else
        {
            Stack.push(Input);
        }
    }

    int Result = 0;
    while (!Stack.empty())
    {
        Result += Stack.top();
        Stack.pop();
    }
    
    std::cout << Result << std::endl;
    
    return 0;
}
