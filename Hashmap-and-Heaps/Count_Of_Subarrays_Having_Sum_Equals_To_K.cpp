#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count_ksum_subarrays(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> sumcount;
    sumcount.insert({0, 1});
    int count = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sumcount.find(sum - k) != sumcount.end())
            count += sumcount[sum - k];
        sumcount[sum]++;
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    cout << count_ksum_subarrays(arr, n, k);

    return 0;
}