#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Pair
{
public:
    int i;
    int c;
    string psf;
    Pair(int i, int c, string psf)
    {
        this->i = i;
        this->c = c;
        this->psf = psf;
    }
};

int Knapsack01(int n, int cap, vector<int> &val, vector<int> &wts, vector<vector<int>> &dp)
{
    for(int i = 1; i <= n; i++)
    {
        for(int c = 0; c <= cap; c++)
        {
            int inc = (c - wts[i-1] >= 0) ? (dp[i-1][c - wts[i-1]] + val[i-1]) : 0;
            int exc = dp[i-1][c];
            dp[i][c] = max(inc, exc);
        }
    }
    return dp[n][cap];
}

int main()
{
    int n, cap;
    cin>>n;
    vector<int> val(n), wts(n);
    for(int i=0; i<n; i++)
        cin>>val[i];
    for(int i=0; i<n; i++)
        cin>>wts[i];
    cin>>cap;
    vector<vector<int>> dp(n+1, vector<int>(cap+1,0));
    int maxval = Knapsack01(n, cap, val, wts, dp);
    
    cout<<maxval<<endl;
    // for(auto v : dp)
    // {
    //     for(int i : v)
    //         cout<<i<<" ";
    //     cout<<endl;
    // }
    
    queue<Pair> que;
    que.push(Pair(n, cap, ""));
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        // cout<<rm.i<<" "<<rm.c<<endl;
        
        if(rm.i == 0 || rm.c == 0)
            cout<<rm.psf<<endl;
        else
        {
            int inc = (rm.c - wts[rm.i-1] >= 0) ? dp[rm.i - 1][rm.c - wts[rm.i-1]] + val[rm.i-1] : -1;
            int exc = dp[rm.i - 1][rm.c];
            if(dp[rm.i][rm.c] == inc)
                que.push(Pair(rm.i - 1, rm.c - wts[rm.i-1], to_string(rm.i-1) + " " + rm.psf));
            else if(dp[rm.i][rm.c] == exc)
                que.push(Pair(rm.i - 1, rm.c, rm.psf));
            // else
            // {
            //     que.push(Pair(rm.i - 1, rm.c - wts[rm.i-1], to_string(rm.i-1) + " " + rm.psf));
            //     que.push(Pair(rm.i - 1, rm.c, rm.psf));
            // }
        }
    }    
}