
// METHOD 1 (recursion -- LEVEL-WISE)
// TLE
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int optimalBST(int si, int ei, int level, vector<int> &key, vector<int> &freq)
{
    if (ei < si)
        return 0;

    int optimal_ans = INT_MAX;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = optimalBST(si, cut - 1, level + 1, key, freq);
        int right = optimalBST(cut + 1, ei, level + 1, key, freq);

        int ans = left + level * freq[cut] + right;
        optimal_ans = min(ans, optimal_ans);
    }
    return optimal_ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> key(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
        cin >> key[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    cout << optimalBST(0, n - 1, 1, key, freq);
}

// METHOD 2 (Memoized)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int freq_cost(vector<int> &freq, int si, int ei)
{
    int ans = 0;
    for (int i = si; i <= ei; i++)
        ans += freq[i];
    return ans;
}

int optimalBST(int si, int ei, int level, vector<int> &key, vector<int> &freq, vector<vector<int>> &dp)
{
    if (ei < si)
        return 0;
    if (dp[si][ei] != -1)
        return dp[si][ei];

    int optimal_ans = INT_MAX;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = optimalBST(si, cut - 1, level + 1, key, freq, dp);
        int right = optimalBST(cut + 1, ei, level + 1, key, freq, dp);

        int ans = left + right;
        optimal_ans = min(ans, optimal_ans);
    }
    return dp[si][ei] = optimal_ans + freq_cost(freq, si, ei);
}

int main()
{
    int n;
    cin >> n;
    vector<int> key(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
        cin >> key[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << optimalBST(0, n - 1, 1, key, freq, dp);
}

// METHOD 3 (Tabulated)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int freq_cost(vector<int> &freq, int si, int ei)
{
    int ans = 0;
    for (int i = si; i <= ei; i++)
        ans += freq[i];
    return ans;
}

int optimalBST(int n, vector<int> &key, vector<int> &freq, vector<vector<int>> &dp)
{
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (gap == 0)
            {
                dp[si][ei] = freq[si];
                continue;
            }
            if (gap == 1)
            {
                int cost_rootsi = freq[si] + 2 * freq[ei];
                int cost_rootei = freq[ei] + 2 * freq[si];
                dp[si][ei] = min(cost_rootsi, cost_rootei);
                continue;
            }
            int optimal_ans = INT_MAX;
            for (int cut = si; cut <= ei; cut++)
            {
                int left = (cut == si) ? 0 : dp[si][cut - 1];
                int right = (cut == ei) ? 0 : dp[cut + 1][ei];
                int ans = left + right;
                optimal_ans = min(ans, optimal_ans);
            }
            dp[si][ei] = optimal_ans + freq_cost(freq, si, ei);
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> key(n);
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
        cin >> key[i];
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << optimalBST(n, key, freq, dp);
}