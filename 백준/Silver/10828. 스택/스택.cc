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
    std::vector<int> Result;
    
    for (int i = 0; i < StackNum; i++)
    {
        std::string Input;
        std::cin >> Input;
        
        if (Input == "push")
        {
            int InputNum;
            std::cin >> InputNum;
            Stack.push(InputNum);
        }
        else if (Input == "top")
        {
            if (Stack.empty())
            {
                Result.push_back(-1);
            }
            else
            {
                Result.push_back(Stack.top());
            }
        }
        else if (Input == "pop")
        {
            if (Stack.empty())
            {
                Result.push_back(-1);
            }
            else
            {
                Result.push_back(Stack.top());
                Stack.pop();
            }
        }
        else if (Input == "size")
        {
            Result.push_back(Stack.size());
        }
        else if (Input == "empty")
        {
            Result.push_back(Stack.empty() ? 1 : 0);
        }
    }

    for (auto result : Result)
    {
        std::cout << result << std::endl;
    }
    
    
    return 0;
}
