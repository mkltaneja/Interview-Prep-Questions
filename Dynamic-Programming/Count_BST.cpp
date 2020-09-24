#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> dp(n+1,0);
    for(int i = 0; i <= n; i++)
    {
        if(i == 0 || i == 1)
        {
            dp[i] = 1;
            continue;
        }
        for(int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i-j-1];
    }
    cout<<dp[n];
    
    return 0;
}