#include<iostream>
#include<climits>
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

int main()
{
    int n, m;
    cin>>n>>m;
    int arr[n][m], dp[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = m-1; j >= 0; j--)
        {
            if(i == n-1 && j == m-1)
            {
                dp[i][j] = arr[i][j];
                continue;
            }
            int a = INT_MAX, b = INT_MAX;
            if(i + 1 < n)
                a = dp[i+1][j];
            if(j + 1 < m)
                b = dp[i][j + 1];
            dp[i][j] = arr[i][j] + min(a, b);
        }
    }
    cout<<dp[0][0]<<endl;
    queue<Pair> que;
    que.push(Pair(0,0,""));
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        
        if(rm.i == n-1 && rm.j == m-1)
            cout<<rm.psf<<endl;
            
        int a = INT_MAX, b = INT_MAX;
        if(rm.i + 1 < n)
            a = dp[rm.i+1][rm.j];
        if(rm.j + 1 < m)
            b = dp[rm.i][rm.j+1];

        if(a < b)
            que.push(Pair(rm.i+1, rm.j, rm.psf + "V"));
        else if(a > b)
            que.push(Pair(rm.i, rm.j+1, rm.psf + "H"));
        else if(rm.i != n-1 || rm.j != m-1)
        {
            que.push(Pair(rm.i+1, rm.j, rm.psf + "V"));
            que.push(Pair(rm.i, rm.j+1, rm.psf + "H"));
        }
    }   
}