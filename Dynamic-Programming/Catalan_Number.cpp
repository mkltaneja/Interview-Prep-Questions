

// // METHOD 1 (recursion)  --> O(n^n)
// #include<iostream>
// using namespace std;

// int Ncatalan(int n)
// {
//     if(n == 0 || n == 1)
//         return 1;
    
//     int ans = 0;
//     for(int i = 0; i < n; i++)
//         ans += Ncatalan(i) * Ncatalan(n-i-1);
//     return ans;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     cout<<Ncatalan(n);
// }

// // METHOD 2 (Tabulation)
// #include<iostream>
// #include<vector>
// using namespace std;

// int Ncatalan(int n, vector<int> &dp)
// {
//     if(n == 0 || n == 1)
//         return dp[n] = 1;
//     if(dp[n] != 0)
//         return dp[n];
//     for(int i = 0; i < n; i++)
//         dp[n] += Ncatalan(i, dp) * Ncatalan(n-i-1, dp);
//     return dp[n];
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,0);
//     cout<<Ncatalan(n, dp);
// }

// METHOD 3 (tabulation)
#include<iostream>
#include<vector>
using namespace std;

int Ncatalan(int N, vector<int> &dp)
{
    for(int n = 0; n <= N; n++)
    {
        if(n == 0 || n == 1)
        {
            dp[n] = 1;
            continue;
        }
        for(int i = 0; i < n; i++)
            dp[n] += dp[i] * dp[n-i-1];
    }
    return dp[N];
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    cout<<Ncatalan(n, dp);
}