#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Pair
{
public:
    int i;
    int j;
    string psf;
    Pair(int i, int j, string psf)
    {
        this->i = i;
        this->j = j;
        this->psf = psf;
    }
};

int Goldmine(int n, int m, vector<vector<int>> &gold, vector<vector<int>> &dp)
{
    int maxgold = -1;
    for(int j = m - 1; j >= 0; j--)
    {
        for(int i = 0; i < n; i++)
        {
            int d1 = (i - 1 >= 0) ? dp[i-1][j+1] : -1;
            int d2 = dp[i][j+1];
            int d3 = (i + 1 < n) ? dp[i+1][j+1] : -1;
            if(d1 >= d2 && d1 >= d3)
                dp[i][j] = gold[i][j] + dp[i-1][j+1];
            else if(d2 >= d1 && d2 >= d3)
                dp[i][j] = gold[i][j] + dp[i][j+1];
            else if(d3 >= d2 && d3 >= d1)
                dp[i][j] = gold[i][j] + dp[i+1][j+1];
                
            if(j == 0)
                maxgold = max(maxgold, dp[i][0]);
        }
    }
    return maxgold;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> gold(n, vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>gold[i][j];
    
    vector<vector<int>> dp(n, vector<int>(m+1,0));
    int maxgold = Goldmine(n, m, gold, dp);
    
    queue<Pair> que;
    for(int i=0; i<n; i++)
        if(dp[i][0] == maxgold)
            que.push(Pair(i, 0, to_string(i) + " "));
    
    cout<<maxgold<<endl;
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        
        if(rm.j == m - 1)
            cout<<rm.psf<<endl;
        
        int d1 = -1, d2 = -1, d3 = -1;
        if(rm.i - 1 >= 0 && rm.j + 1 < m)
            d1 = dp[rm.i-1][rm.j+1];
        if(rm.j + 1 < m)
            d2 = dp[rm.i][rm.j+1];
        if(rm.i + 1 < n && rm.j + 1 < m)
            d3 = dp[rm.i+1][rm.j+1];
        int maxg = max(d1, max(d2, d3));
        
        if(d1 == maxg && d1 != -1)
            que.push(Pair(rm.i - 1, rm.j + 1, rm.psf + "d1 "));
        if(d2 == maxg && d2 != -1)
            que.push(Pair(rm.i, rm.j + 1, rm.psf + "d2 "));
        if(d3 == maxg && d3 != -1)
            que.push(Pair(rm.i + 1, rm.j + 1, rm.psf + "d3 "));
    }
}