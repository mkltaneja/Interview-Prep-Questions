#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    // cout<<n<<" "<<m<<endl;
    vector<vector<bool>> dp(m+1, vector<bool>(n+1,0));
    
    dp[0][0] = true;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j == 0)
            {
                if((s2[i-1] == '*') && (dp[i-2][j]))
                    dp[i][j] = true;
                cout<<dp[i][j]<<" ";
                continue;
            }
            
            if(s2[i-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else if(s2[i-1] == '*')
                dp[i][j] = dp[i-2][j] || dp[i][j-1];
            else 
                dp[i][j] = (s1[j-1] == s2[i-1] && dp[i-1][j-1]);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<(boolalpha)<<dp[m][n];
    
    return 0;
}