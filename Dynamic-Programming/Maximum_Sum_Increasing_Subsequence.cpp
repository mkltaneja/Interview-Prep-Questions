#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> sum = arr;
    for(int i=1; i<n; i++)
        for(int j=i-1; j >= 0; j--)
            if(arr[j] <= arr[i] && sum[j]+arr[i] > sum[i])
                sum[i] = sum[j] + arr[i];
    int maxsum = 0;
    for(int j : sum)
        maxsum = max(maxsum, j);
    cout<<maxsum;
    
    return 0;
}