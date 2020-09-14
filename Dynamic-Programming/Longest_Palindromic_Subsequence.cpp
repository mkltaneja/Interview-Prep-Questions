
// METHOD 2 (Recursion)
#include<iostream>
using namespace std;

int maxpallen(int i, int j, string &s)
{
    if(i > j)
        return 0;
    if(i == j)
        return 1;
        
    int len = 0;
    if(s[i] == s[j])
        len = maxpallen(i+1, j-1, s) + 2;
    else
        len = max(maxpallen(i+1, j, s), maxpallen(i, j-1, s));
    
    return len;
}

int main()
{
    string s;
    cin>>s;
    cout<<maxpallen(0,s.size()-1,s);
}

// METHOD 2(Memoization)
#include<iostream>
#include<vector>
using namespace std;

int maxpallen(int i, int j, string &s, vector<vector<int>> &dp)
{
    if(i > j)
        return dp[i][j] = 0;
    if(i == j)
        return dp[i][j] = 1;
    if(dp[i][j] != -1)
        return dp[i][j];
        
    if(s[i] == s[j])
        dp[i][j] = maxpallen(i+1, j-1, s, dp) + 2;
    else
        dp[i][j] = max(maxpallen(i+1, j, s, dp), maxpallen(i, j-1, s, dp));
    
    return dp[i][j];
}

int main()
{
    string s;
    cin>>s;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    cout<<maxpallen(0, s.size()-1, s, dp);
}

// METHOD 3 (TABULATION)
#include<iostream>
#include<vector>
using namespace std;

int maxpallen(string &s, vector<vector<int>> &dp)
{
    for(int gap = 0; gap < s.size(); gap++)
    {
        for(int i=0, j=gap; j < s.size(); i++, j++)
        {
            if(gap == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            
            if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][s.size()-1];
}

int main()
{
    string s;
    cin>>s;
    vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
    cout<<maxpallen(s, dp);
}