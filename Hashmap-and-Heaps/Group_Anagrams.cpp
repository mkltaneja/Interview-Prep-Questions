#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isvalid_anagram(string s, string t)
{
    if(s.size() != t.size())
        return false;
    unordered_map<char, int> m;
    for(char c : s)
        m[c]++;
    for(char c : t)
        if(--m[c] == 0)
            m.erase(c);
    return m.size() == 0;
}

void group_anagrams(int n, vector<string> &ss)
{
    unordered_map<string,vector<string>> ans;
    
    for(string s : ss)
    {
        bool f = false;
        if(ans.empty())
        {
            f = true;
            ans.insert({s,{s}});
            continue;
        }
        for(auto p : ans)
        {
            if(isvalid_anagram(s, p.first))
            {
                f = true;
                ans[p.first].push_back(s);
            }
        }
        // cout<<f<<endl;
        if(!f)
            ans.insert({s,{s}});
    }
    
    for(auto p : ans)
    {
        for(string s : ans[p.first])
            cout<<s<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> ss(n);
    
    for(int i = 0; i < n; i++)
        cin>>ss[i];
    
    group_anagrams(n, ss);
}