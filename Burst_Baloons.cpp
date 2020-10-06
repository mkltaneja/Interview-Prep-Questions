
// METHOD 1 (Recursive)
// TLE
#include <iostream>
#include <vector>
using namespace std;

int Burst_Baloons(int si, int ei, vector<int> &arr)
{
    int leftcost = (si == 0) ? 1 : arr[si - 1];
    int rightcost = (ei == arr.size() - 1) ? 1 : arr[ei + 1];
    int maxcoins = 0;
    for (int cut = si; cut <= ei; cut++)
    {
        int leftans = (cut == si) ? 0 : Burst_Baloons(si, cut - 1, arr);
        int rightans = (cut == ei) ? 0 : Burst_Baloons(cut + 1, ei, arr);

        int myans = leftans + leftcost * arr[cut] * rightcost + rightans;
        maxcoins = max(maxcoins, myans);
    }
    return maxcoins;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Burst_Baloons(0, n - 1, arr);
}

// METHOD 2 (Memoized)
#include <iostream>
#include <vector>
using namespace std;

int Burst_Baloons(int si, int ei, vector<int> &arr, vector<vector<int>> &dp)
{
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int leftcost = (si == 0) ? 1 : arr[si - 1];
    int rightcost = (ei == arr.size() - 1) ? 1 : arr[ei + 1];
    int maxcoins = 0;
    for (int cut = si; cut <= ei; cut++)
    {
        int leftans = (cut == si) ? 0 : Burst_Baloons(si, cut - 1, arr, dp);
        int rightans = (cut == ei) ? 0 : Burst_Baloons(cut + 1, ei, arr, dp);

        int myans = leftans + leftcost * arr[cut] * rightcost + rightans;
        maxcoins = max(maxcoins, myans);
    }
    return dp[si][ei] = maxcoins;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << Burst_Baloons(0, n - 1, arr, dp);
}

// METHOD 3 (TABULATED)
#include <iostream>
#include <vector>
using namespace std;

int Burst_Baloons(int n, vector<int> &arr, vector<vector<int>> &dp)
{
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            int leftcost = (si == 0) ? 1 : arr[si - 1];
            int rightcost = (ei == n - 1) ? 1 : arr[ei + 1];
            int maxcoins = 0;
            for (int cut = si; cut <= ei; cut++)
            {
                int leftans = (cut == si) ? 0 : dp[si][cut - 1];
                int rightans = (cut == ei) ? 0 : dp[cut + 1][ei];

                int myans = leftans + leftcost * arr[cut] * rightcost + rightans;
                maxcoins = max(maxcoins, myans);
            }
            dp[si][ei] = maxcoins;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << Burst_Baloons(n, arr, dp);
}