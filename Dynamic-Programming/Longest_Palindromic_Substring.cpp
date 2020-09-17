#include<iostream>
#include<vector>
using namespace std;

int longestpalstr(int n, string &s, vector<vector<bool>> &ispal)
{
    int maxlen = 0;
    for(int gap = 0; gap < n; gap++)
    {
        for(int i=0, j=gap; j < n; i++, j++)
        {
            if(gap == 0)
                ispal[i][j] = true;
            else if(gap == 1)
                ispal[i][j] = (s[i] == s[j]);
            else
                ispal[i][j] = (s[i] == s[j] && ispal[i+1][j-1]);
            if(ispal[i][j])
                maxlen = gap + 1;
        }
    }
    return maxlen;
}

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<bool>> ispal(n,vector<bool>(n,0));
    cout<<longestpalstr(n, s, ispal);
}