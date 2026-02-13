#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> NumList;
    
    int Space = s.find(' ');
    int Index = 0;
    
    while(Space != string::npos)
    {
        string NumStr = s.substr(Index,Space-Index);
        
        Index = Space + 1;
        Space = s.find(' ',Index);
        
        int Num = stoi(NumStr);
        
        NumList.emplace_back(Num);
    }
    
    string NumStr = s.substr(Index,Space-Index);
    int Num = stoi(NumStr);
    
    NumList.emplace_back(Num);
    
    int MinNum = *min_element(NumList.begin(),NumList.end());
    int MaxNum = *max_element(NumList.begin(),NumList.end());
    
    answer += to_string(MinNum);
    answer += " ";
    answer += to_string(MaxNum);
    
    return answer;
}