#include<iostream>
using namespace std;

bool ispalindrome(string &s)
{
    for(int i=0; i<s.size(); i++)
        if(s[i] != s[s.size()-i-1])
            return false;
    return true;
}

void palpartitions(int idx, int n, string &s, string ans)
{
    if(idx == n)
    {
        cout<<ans<<endl;
        return;
    }
    
    string str = "";
    for(int i=idx; i<n; i++)
    {
        str += s[i];
        if(ispalindrome(str))
            palpartitions(i+1, n, s, ans+"("+str+") ");
    }
}

int main()
{
    string s;
    cin>>s;
    palpartitions(0,s.size(),s,"");
}