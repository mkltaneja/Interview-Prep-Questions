
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
