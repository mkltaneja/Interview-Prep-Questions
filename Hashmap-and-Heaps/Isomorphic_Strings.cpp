#include<iostream>
#include<unordered_map>
using namespace std;

bool are_isomorphic(string &s, string &t)
{
    if(s.size() != t.size())
        return false;
        
    unordered_map<char, char> mst;
    unordered_map<char, char> mts;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(mst.find(s[i]) == mst.end() && mts.find(t[i]) == mts.end())
        {
            mst.insert({s[i],t[i]});
            mts.insert({t[i],s[i]});
        }
        else if(mst.find(s[i]) != mst.end() && t[i] != mst[s[i]])
            return false;
        else if(mts.find(t[i]) != mts.end() && s[i] != mts[t[i]])
            return false;
    }
    return true;
}

int main()
{
    string s, t;
    cin>>s>>t;
    
    cout<<(boolalpha)<<are_isomorphic(s, t);
}