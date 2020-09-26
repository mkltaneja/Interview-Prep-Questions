#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n == 1)
        cout<<0<<endl;
    else
    {
        n -= 2;
        vector<int> dp(n+1,0);
        for(int i = 0; i <= n; i++)
        {
            if(i == 0 || i == 1)
            {
                dp[i] = 1;
                continue;
            }
            int base1 = 0;
            int base2 = i - 1;
            while(base2 >= 0)
                dp[i] += dp[base1++] * dp[base2--];
        }
        cout<<dp[n];
    }
    return 0;
}