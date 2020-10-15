#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int count_zerosum_subarrays(int n, vector<int> &arr)
{
    int count = 0;
    unordered_map<int, int> sumatpos;
    int sum = 0;
    sumatpos.insert({sum, 1});
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sumatpos.find(sum) == sumatpos.end())
            sumatpos.insert({sum, 1});
        else
            count += sumatpos[sum]++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << count_zerosum_subarrays(n, arr);

    return 0;
}