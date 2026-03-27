#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int TotalNum, FindNum;
    map<string,string> SiteList;
    
    cin >> TotalNum >> FindNum;
    
    for (int i = 0; i < TotalNum; i++)
    {
        string SiteName,PassWord;
        
        cin >> SiteName >> PassWord;
        SiteList.insert(pair<string,string>(SiteName,PassWord));
    }
    
    for (int i = 0; i < FindNum; i++)
    {
        string FindSite;
        cin >> FindSite;
        cout << SiteList.find(FindSite)->second << "\n";
    }
}
