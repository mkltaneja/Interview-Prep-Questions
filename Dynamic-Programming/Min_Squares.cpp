
// Recursive
#include <iostream>
#include <climits>
using namespace std;

int minsquares(int n)
{
    if (n == 0)
        return 0;
    int minans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
        minans = min(minans, minsquares(n - i * i) + 1);
    return minans;
}

int main()
{
    int n;
    cin >> n;
    cout << minsquares(n);

    return 0;
}

// MEMOIZED
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minsquares(int n, vector<int> &dp)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    int minans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
        minans = min(minans, minsquares(n - i * i, dp) + 1);
    return dp[n] = minans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << minsquares(n, dp);

    return 0;
}

// Tabulation
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minsquares_tab(int N, vector<int> &dp)
{
    for (int n = 0; n <= N; n++)
    {
        if (n == 0 || n == 1 || n == 2 || n == 3)
        {
            dp[n] = n;
            continue;
        }

        int minans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
            minans = min(minans, dp[n - i * i] + 1);
        dp[n] = minans;
    }
    return dp[N];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << minsquares_tab(n, dp);

    return 0;
}