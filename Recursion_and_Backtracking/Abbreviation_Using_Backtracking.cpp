#include<iostream>
using namespace std;

void abbreviations(string &que, string ans, int count, int i)
{
    if(i == que.size())
    {
        if(count == 0)
            cout<<ans<<endl;
        else
            cout<<ans<<count<<endl;
        return;
    }
    if(count == 0)
        abbreviations(que, ans+que[i], 0, i+1);
    else
        abbreviations(que, ans+to_string(count)+que[i], 0, i+1);
    abbreviations(que, ans, count+1, i+1);
    
    return;
}

int main()
{
    string s;
    cin>>s;
    abbreviations(s,"",0,0);
    return 0;
}