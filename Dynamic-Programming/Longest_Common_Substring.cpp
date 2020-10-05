
// Method 1 --> O(3^n)
#include<iostream>
using namespace std;

int maxlen = 0;
void longestcommon_substring(int i, int j, int len, string s, string t)
{
    maxlen = max(maxlen, len);
    if(i == s.size() || j == t.size())
        return;
    
    if(s[i] == t[j])
        longestcommon_substring(i + 1, j + 1, len + 1, s, t);
    
    longestcommon_substring(i + 1, j, 0, s, t);
    longestcommon_substring(i, j + 1, 0, s, t);
}

int main()
{
    string s, t;
    cin>>s>>t;
    longestcommon_substring(0, 0, 0, s, t);
    cout<<maxlen;
}