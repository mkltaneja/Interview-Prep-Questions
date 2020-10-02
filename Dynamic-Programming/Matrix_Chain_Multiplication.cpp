
// METHOD 1 (Recursion)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MCM_rec(int si, int ei, vector<int> &arr)
{
    if (si + 1 == ei)
        return 0;

    int minans = INT_MAX;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int leftmatrix = MCM_rec(si, cut, arr);
        int rightmatrix = MCM_rec(cut, ei, arr);

        int ans = leftmatrix + arr[si] * arr[cut] * arr[ei] + rightmatrix;

        minans = min(ans, minans);
    }
    return minans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << MCM_rec(0, n - 1, arr);
}

// METHOD 2 (Memoized)
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MCM_rec(int si, int ei, vector<int> &arr, vector<vector<int>> &dp)
{
    if(si + 1 == ei)
        return dp[si][ei] = 0;
    if(dp[si][ei] != -1)
        return dp[si][ei];
    
    int minans = INT_MAX;
    for(int cut = si + 1; cut < ei; cut++)
    {
        int leftmatrix = MCM_rec(si, cut, arr, dp);
        int rightmatrix = MCM_rec(cut, ei, arr, dp);
        
        int ans = leftmatrix + arr[si] * arr[cut] * arr[ei] + rightmatrix;
        
        minans = min(ans, minans);
    }
    
    return dp[si][ei] = minans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    cout<<MCM_rec(0, n-1, arr, dp);
}