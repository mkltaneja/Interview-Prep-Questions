
// METHOD 1 --> O((n^2)*logn)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int largest_contiguous_subarray(int n, vector<int> &arr)
{
    int maxlen = 1;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> vis;
        int maxele = arr[i], minele = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (vis.find(arr[j]) != vis.end())
                break;
            vis.insert(arr[j]);
            maxele = max(maxele, arr[j]);
            minele = min(minele, arr[j]);
            if ((maxele - minele) == (j - i))
                maxlen = max(maxlen, (j - i + 1));
            // cout<<maxele - minele<<" "<<j - i<<": "<<maxlen<<",   ";
        }
        // cout<<endl;
    }
    return maxlen;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << largest_contiguous_subarray(n, arr);
}