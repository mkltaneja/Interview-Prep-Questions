
// APPROACH 1 (Checking all subsequences)
// METHOD 1  --> O(n*2^n)
#include<iostream>
using namespace std;

bool ispal(string &s)
{
    int i = 0, j = s.size()-1;
    while(i < j)
        if(s[i++] != s[j--])
            return false;
    return true;
}

int subsequence_pal(int idx, string ans, string &s)
{
    if(idx == s.size())
    {
        if(ans != "" && ispal(ans))
            return 1;
        return 0;
    }
    int countpal = 0;
    countpal += subsequence_pal(idx+1, ans+s[idx], s) + subsequence_pal(idx+1, ans, s);
    
    return countpal;
}

int main()
{
    string s;
    cin>>s;
    cout<<subsequence_pal(0, "", s);
}

///////////////////////////////////////////////////OR////////////////////////////////////////

// APPROACH 2 (by cutting the end characters of string recursively)
// METHOD 3  --> O(3^n)
#include<iostream>
using namespace std;

int countps(int i, int j, string &s)
{
    if(i > j)
        return 0;
    if(i == j)
        return 1;
    int middle_string = countps(i+1, j-1, s);
    int exclude_prefix = countps(i+1, j, s);
    int exclude_suffix = countps(i, j-1, s);
    
    if(s[i] == s[j])
        return exclude_prefix + exclude_suffix + 1;
    else
        return exclude_prefix + exclude_suffix - middle_string;
}

int main()
{
    string s;
    cin>>s;
    cout<<countps(0, s.size()-1, s);
}

// METHOD 3 (Memoized) --> O(n^2)
#include<iostream>
#include<vector>
using namespace std;

int countps(int i, int j, string &s, vector<vector<int>> &dp)
{
    if(i > j)
        return dp[i][j] = 0;
    if(i == j)
        return dp[i][j] = 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    int middle_string = countps(i+1, j-1, s, dp);
    int exclude_prefix = countps(i+1, j, s, dp);
    int exclude_suffix = countps(i, j-1, s, dp);
    
    int ans = exclude_prefix + exclude_suffix;
    if(s[i] == s[j])
        return dp[i][j] = ans + 1;
    else
        return dp[i][j] = ans - middle_string;
}

int main()
{
    string s;
    cin>>s;
    vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
    cout<<countps(0, s.size()-1, s, dp);
}