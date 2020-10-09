
// APPROACH 1 (Naive) --> O(n*k)
#include <iostream>
#include <vector>
using namespace std;

int kConcatenation(int n, int k, vector<int> &arr)
{
    int sum = 0, maxsum = -1e7;
    for (int i = 0; k; i = (i + 1) % n)
    {
        sum += arr[i];
        maxsum = max(sum, maxsum);
        if (sum < 0)
            sum = 0;
        if (i == n - 1)
            k--;
    }
    return maxsum;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << kConcatenation(n, k, arr);
}

// APPROACH 2 --> O(2*n)
#include <iostream>
#include <vector>
using namespace std;

int Kedanes(int n, vector<int> &arr)
{
    int sum = 0, maxsum = -1e7;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxsum = max(sum, maxsum);
        if (sum < 0)
            sum = 0;
    }
    return maxsum;
}

int kConcatenation(int n, int k, vector<int> &arr, int arrsum)
{
    int ans;
    if (k == 1)
        return Kedanes(arr.size() / 2, arr);
    else
        ans = Kedanes(arr.size(), arr);
    ans += (arrsum > 0) ? (k - 2) * arrsum : 0;
    return ans;
}

int main()
{
    int n, k, sum = 0;
    cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[n + i] = arr[i];
        sum += arr[i];
    }
    cin >> k;
    cout << kConcatenation(n, k, arr, sum);
}
