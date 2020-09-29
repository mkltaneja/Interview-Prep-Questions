
// APPROACH 1 (Recursion)  --> O(n^n)
// TLE
#include<iostream>
#include<vector>
using namespace std;

void rod_cutting(int idx, int n, int tar, vector<int> &arr, int profit, int &maxprofit)
{
    if(tar == 0)
    {
        maxprofit = max(maxprofit, profit);
        return;
    }
    for(int i = idx; i < n; i++)
        if(tar - (i+1) >= 0)
            rod_cutting(i, n, tar-(i+1), arr, profit+arr[i], maxprofit);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int maxprofit = 0;
    rod_cutting(0, n, n, arr, 0, maxprofit);
    cout<<maxprofit;
}
