#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

string ascii_diff(string &s)
{
    string pat = "#";
    
    for(int i = 1; i < s.size(); i++)
    {
        int num = (s[i] - s[i-1]);
        if(num < 0)
            num += 26;
        pat += num + '0';
        pat += "#";
    }
        
    return pat;
}

void group_shifted_strings(int n, vector<string> ss)
{
    unordered_map<string,vector<string>> m;
    
    for(string s : ss)
    {
        string pat = ascii_diff(s);
        
        if(m.find(pat) != m.end())
            m[pat].push_back(s);
        else
            m.insert({pat,{s}});
    }
    
    for(auto p : m)
    {
        cout<<p.first<<":   ";
        for(string s : m[p.first])
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
    
    group_shifted_strings(n, ss);
    
    return 0;
}