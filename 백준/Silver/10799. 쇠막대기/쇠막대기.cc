#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string T;
    cin >> T;
    
    int result = 0;
    stack<char> v;
    for (int i = 0; i < T.length(); i++)
    {
        if (T[i] == '(')
        {
            v.push(T[i]);
        }
        else if (T[i] == ')')
        {
            v.pop();
            
            if (T[i-1] == '(')
            {
                result += v.size();
            }
            else
            {
                result++;
            }
        }
        
    }
    
    cout << result << '\n';
}
