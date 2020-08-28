#include<iostream>
#include<map>
#include<vector>
using namespace std;

void display(vector<string> &pat, string &s)
{
    vector<bool> vis(26,false);
    for(char c : s)
    {
        if(!vis[c - 'a'])
        {
            vis[c - 'a'] = true;
            cout<<c<<" -> "<<pat[c - 'a']<<", ";
        }
    }
    cout<<"."<<endl;
}

void pattern_matching(int idx , string str, string &ptr, vector<string> &pat)
{
    if(idx == ptr.size())
    {
        if(str.size() == 0)
            display(pat, ptr);
        return;
    }
    int j = ptr[idx] - 'a';
    if(pat[j] == "")
    {
        for(int i=1; i<str.size(); i++)
        {
            pat[j] = str.substr(0,i);
            pattern_matching(idx+1, str.substr(i), ptr, pat);
            pat[j] = "";
        }
    }
    else if(pat[j] == str.substr(0,pat[j].size()))
        pattern_matching(idx+1, str.substr(pat[j].size()), ptr, pat);
}

int main()
{
    string str, ptr;
    cin>>str>>ptr;
    vector<string> pat(26);
    pattern_matching(0, str, ptr, pat);
}
