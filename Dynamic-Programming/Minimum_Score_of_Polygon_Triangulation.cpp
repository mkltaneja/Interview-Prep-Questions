#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> val(n,0);
    for(int i=0; i<n; i++)
        cin>>val[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {
            if(gap == 0 || gap == 1)
                dp[i][j] = 0;
            else if(gap == 2)
                dp[i][j] = val[i] * val[i+1] * val[i+2];
            else
            {
                int Score = INT_MAX;
                for(int x = i+1; x < j; x++)
                {
                    int base = val[i] * val[x] * val[j];
                    int side1 = dp[i][x];
                    int side2 = dp[x][j];
                    Score = min(Score, (base + side1 + side2));
                }
                dp[i][j] = Score;
            }
        }
    }
    // for(auto v : dp)
    // {
    //     for(int i : v)
    //         cout<<i<<" \t";
    //     cout<<endl;
    // }
    cout<<dp[0][n-1];
    
    return 0;
}