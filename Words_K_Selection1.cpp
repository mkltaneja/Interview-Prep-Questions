
// METHOD 1 (calling boxes-wise)

#include<iostream>
#include<vector>
using namespace std;

void kselection(int idx, string s, int k, int K, string ans)
{
    if(k == K)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=idx; i<s.size(); i++)
        kselection(i+1, s, k+1, K, ans+s[i]);
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    vector<bool> vis(26,false);
    string unique = "";
    for(char c : s)
    {
        if(!vis[c - 'a'])
        {
            vis[c - 'a'] = true;
            unique += c;
        }
    }
    kselection(0, unique, 0, k, "");
}

///////////////////////////////////////////////////////OR////////////////////////////////////////////////////

// METHOD 2 (Using subsequence --> calling character-wise)
#include<iostream>
#include<vector>
using namespace std;

void kselection(int idx, string s, int k, int K, string ans)
{
    if(idx == s.size())
    {
        if(k == K)
            cout<<ans<<endl;
        return;
    }
    kselection(idx+1, s, k+1, K, ans+s[idx]);
    kselection(idx+1, s, k, K, ans);
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    vector<bool> vis(26,false);
    string unique = "";
    for(char c : s)
    {
        if(!vis[c - 'a'])
        {
            vis[c - 'a'] = true;
            unique += c;
        }
    }
    kselection(0, unique, 0, k, "");
}