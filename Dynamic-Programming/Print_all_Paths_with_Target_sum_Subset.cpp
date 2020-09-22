#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Pair
{
public:
    int idx;
    int tar;
    string psf;
    Pair(int i, int j, string psf)
    {
        this->idx = i;
        this->tar = j;
        this->psf = psf;
    }
};

bool coinChange_dp(int n, int tar, vector<int> &coins, vector<vector<bool>> &dp)
{
    for(int i = 0; i <= n; i++)
    {
        for(int t = 0; t <= tar; t++)
        {
            if(t == 0)
            {
                dp[i][t] = true;
                continue;
            }
            if(i != 0)
                if((t-coins[i] >= 0 && dp[i-1][t-coins[i]]) || (dp[i-1][t]))  // contribution or no contribution
                    dp[i][t] = true;
        }
    }
    return dp[n][tar];
}

int main()
{
    int n, tar;
    cin>>n;
    vector<int> coins(n+1);
    for(int i=1; i<=n; i++)
        cin>>coins[i];
    cin>>tar;
    
    vector<vector<bool>> dp(n+1, vector<bool>(tar+1,0));
    cout<<(boolalpha)<<coinChange_dp(n, tar, coins, dp)<<endl;
    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=tar; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    
    queue<Pair> que;
    que.push(Pair(n,tar,""));
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        // cout<<rm.idx<<" "<<rm.tar<<" -> "<<rm.psf<<endl;
        if(rm.idx == 0 || rm.tar == 0)
            cout<<rm.psf<<endl;
        else
        {
            if(rm.tar - coins[rm.idx] >= 0 && dp[rm.idx - 1][rm.tar - coins[rm.idx]])  //with contribution
                que.push(Pair(rm.idx - 1, rm.tar - coins[rm.idx], to_string(rm.idx-1) + " " + rm.psf));
            if(dp[rm.idx - 1][rm.tar])  // without contribution
                que.push(Pair(rm.idx - 1, rm.tar, rm.psf));
        }
    }   
}