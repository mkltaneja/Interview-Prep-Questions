#include<iostream>
#include<vector>
using namespace std;

void LIS(int n, vector<int> &arr, vector<int> &len)
{
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j] < arr[i] && len[j]+1 > len[i])
                len[i] = len[j] + 1;
}

void LDS(int n, vector<int> &arr, vector<int> &len)
{
    for(int i=n-2; i>=0; i--)
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[i] && len[j]+1 > len[i])
                len[i] = len[j] + 1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<int> maxinc_len(n,1);
    vector<int> maxdec_len(n,1);
    LIS(n,arr,maxinc_len);
    LDS(n,arr,maxdec_len);
    
    int LBS_len = 1;
    for(int i=0; i<n; i++)
        LBS_len = max(LBS_len, maxinc_len[i]+maxdec_len[i]-1);
    
    cout<<LBS_len<<endl;
    
    return 0;
}