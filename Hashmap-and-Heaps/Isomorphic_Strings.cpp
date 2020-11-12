#include<iostream>
#include<unordered_map>
using namespace std;

bool are_isomorphic(string &s, string &t)
{
    if(s.size() != t.size())
        return false;
        
    unordered_map<char, char> mapst;
    unordered_map<char, bool> ismapped;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(mapst.find(s[i]) != mapst.end() && t[i] != mapst[s[i]])
            return false;
        if(mapst.find(s[i]) == mapst.end() && ismapped[t[i]])
            return false;
        mapst[s[i]] = t[i];
        ismapped[t[i]] = true;
    }
    return true;
}

int main()
{
    string s, t;
    cin>>s>>t;
    
    cout<<(boolalpha)<<are_isomorphic(s, t);
}