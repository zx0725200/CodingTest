#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int Num;
    cin >> Num;
    
    int Result = 0;
    constexpr int MaxNum = 100;
    bool Board[MaxNum][MaxNum] = {false};
    
    for (int i = 1; i <= Num; i++)
    {
        int x,y;
        cin >> x >> y;
        
        for (int Ver = x; Ver < x+10; Ver++)
        {
            for (int Hor = y; Hor < y+10; Hor++)
            {
                if (!Board[Ver][Hor])
                {
                    Result++;
                }
                
                Board[Ver][Hor] = true;
            }
        }
    }
    
    cout << Result << endl;
}