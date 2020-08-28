#include<iostream>
#include<unordered_set>
using namespace std;

void wordbreak(string que, unordered_set<string> &dict, string ans)
{
    if(que.size() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    string s = "";
    for(int i=0; i<que.size(); i++)
    {
        s += que[i];
        if(dict.find(s) != dict.end())
            wordbreak(que.substr(s.size()), dict, ans+s+" ");
    }
}

int main()
{
    int n;
    cin>>n;
    unordered_set<string> dict;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        dict.insert(s);
    }
    string sent;
    cin>>sent;
    wordbreak(sent, dict, "");
}