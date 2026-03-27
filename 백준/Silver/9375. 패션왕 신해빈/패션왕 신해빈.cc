#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        map<string, int> clothes;

        for (int i = 0; i < N; i++)
        {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }
        
        long result = 1;
        for (auto it : clothes)
            result *= (it.second + 1);
        
        cout << result - 1 << "\n";
    }
}