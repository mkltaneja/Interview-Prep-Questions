
// METHOD 1 (void - type)
#include<iostream>
using namespace std;

int maxcom = 0;
void LCS(int i1, int i2, string &s1, string &s2, int com)
{
    if(i1 == s1.size() || i2 == s2.size())
    {
        maxcom = max(maxcom, com);
        return;
    }
    if(s1[i1] == s2[i2])
        LCS(i1+1, i2+1, s1, s2, com+1);
    else
    {
        LCS(i1+1, i2, s1, s2, com);
        LCS(i1, i2+1, s1, s2, com);
    }
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    LCS(0, 0, s1, s2, 0);
    cout<<maxcom;
    return 0;
}

// METHOD 2(int - type)
#include<iostream>
using namespace std;

int LCS(int i1, int i2, string &s1, string &s2)
{
    if(i1 == s1.size() || i2 == s2.size())
        return 0;
        
    int maxcom = 0;
    if(s1[i1] == s2[i2])
        maxcom = LCS(i1+1, i2+1, s1, s2) + 1;
    else
        maxcom = max(LCS(i1+1, i2, s1, s2), LCS(i1, i2+1, s1, s2));
    
    return maxcom;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<LCS(0, 0, s1, s2);
    return 0;
}

// METHOD 3 (Memoization)
#include<iostream>
#include<vector>
using namespace std;

int LCS(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i1 == s1.size() || i2 == s2.size())
        return dp[i1][i2] = 0;
    
    if(dp[i1][i2] != -1)
        return dp[i1][i2];
        
    if(s1[i1] == s2[i2])
        dp[i1][i2] = LCS(i1+1, i2+1, s1, s2, dp) + 1;
    else
        dp[i1][i2] = max(LCS(i1+1, i2, s1, s2, dp), LCS(i1, i2+1, s1, s2, dp));
    
    return dp[i1][i2];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
    cout<<LCS(0, 0, s1, s2, dp);
    return 0;
}

// METHOD 4 (Tabulation)
#include<iostream>
#include<vector>
using namespace std;

int LCS(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
{
    for(int i=s1.size(); i >= 0; i--)
    {
        for(int j=s2.size(); j >= 0; j--)
        {
            if(i == s1.size() || j == s2.size())
            {
                dp[i][j] = 0;
                continue;
            }
        
            if(s1[i] == s2[j])
                dp[i][j] = dp[i+1][j+1] + 1;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    cout<<LCS(0, 0, s1, s2, dp);
    return 0;
}