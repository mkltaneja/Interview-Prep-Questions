#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kedanesalgo(int n, vector<int> &arr)
{
    int sum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxsum = max(sum, maxsum);
        if (sum < 0)
            sum = 0;
    }
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kedanesalgo(n, arr);
}