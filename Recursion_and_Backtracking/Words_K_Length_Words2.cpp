
// calling index wise (boxes wise)

#include<iostream>
#include<vector>
using namespace std;

void klen(string &s, int k, int K, vector<bool> &vis, string ans)
{
    if(k == K)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            klen(s, k+1, K, vis, ans+s[i]);
            vis[i] = false;
        }
    }
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
    vector<bool> boxes(s.size(),false);
    klen(unique, 0, k, boxes, "");
}
