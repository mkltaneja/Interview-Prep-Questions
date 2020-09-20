#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

class Pair
{
public:
    int i;
    string psf;
    Pair(int idx, string psf)
    {
        this->i = idx;
        this->psf = psf;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<int> dp(n,INT_MAX);
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--)
    {
        for(int j = i+1; j <= i + arr[i] && j < n; j++)
        {
            if(dp[j] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    queue<Pair> que;
    que.push(Pair(0, to_string(0)));
    cout<<dp[0]<<endl;
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        if(rm.i == n-1)
            cout<<rm.psf<<" ."<<endl;
        for(int j = rm.i + 1; j <= rm.i + arr[rm.i] && j < n; j++)
            if(dp[j] == dp[rm.i] - 1)
                que.push(Pair(j, rm.psf + " -> " + to_string(j)));
    }
}
