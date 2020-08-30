
// APPROACH - calling item-wise

#include<iostream>
#include<vector>
using namespace std;

void kselection(int idx, string &s, int k, int K, vector<char> &boxes)
{
    if(idx == s.size())
    {
        if(k == K)
        {
            for(char c : boxes)
                cout<<c;
            cout<<endl;
        }
        return;
    }
    for(int i=0; i<K; i++)
    {
        if(!boxes[i])
        {
            boxes[i] = s[idx];
            kselection(idx+1, s, k+1, K, boxes);
            boxes[i] = NULL;
        }
    }
    kselection(idx+1, s, k, K, boxes);
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
    vector<char> used(k, false);
    kselection(0, unique, 0, k, used);
}
