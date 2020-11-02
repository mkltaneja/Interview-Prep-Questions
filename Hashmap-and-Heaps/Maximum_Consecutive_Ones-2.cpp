#include <iostream>
#include <vector>
using namespace std;

int maxconsec_ones(int n, int k, vector<int> &arr)
{
    int maxlen = 0;
    int j = 0, zeros = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zeros++;
        while (zeros == k + 1)
        {
            if (arr[j] == 0)
                zeros--;
            j++;
        }
        maxlen = max(maxlen, i - j + 1);
    }
    return maxlen;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    cout << maxconsec_ones(n, k, arr) << endl;

    return 0;
}