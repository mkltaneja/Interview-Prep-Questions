
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