
// Method 1 (Void Type) --> O(3^n)
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

// METHOD 2 (Int type) --> < O(3^n)
#include<iostream>
#include<vector>
using namespace std;

int maxlen = 0;
int longest_common_substring(int i, int j, string &s, string &t)
{
    if(i == s.size() || j == t.size())
        return 0;
    if(s[i] == t[j])
    {
        int com = longest_common_substring(i + 1, j + 1, s, t) + 1;
        maxlen = max(maxlen, com);
        return com;
    }
    
    longest_common_substring(i + 1, j, s, t);
    longest_common_substring(i, j + 1, s, t);
    
    return 0;
}

int main()
{
    string s, t;
    cin>>s>>t;
    longest_common_substring(0, 0, s, t);
    cout<<maxlen;
    
    return 0;
}