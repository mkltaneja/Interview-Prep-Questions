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
        int reg1 = 0, reg2 = i - 1;
        while(reg2 >= 0)
            dp[i] += dp[reg1++] * dp[reg2--];
    }
    cout<<dp[n];
    
    return 0;
}