
// METHOD 1 --> O(n*(2^n))
#include<iostream>
#include<vector>
using namespace std;

void subsequence(int i, int idx, int n, vector<int> &arr, int len, int &maxl)
{
    if(idx == n)
    {
        maxl = max(len, maxl);
        return;
    }
    if(arr[idx] > arr[i])
    {
        // cout<<arr[idx]<<" "<<arr[i]<<" "<<len<<endl;
        subsequence(idx, idx+1, n, arr, len+1, maxl);
    }
    subsequence(i, idx+1, n, arr, len, maxl);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int maxlen = 1;
    for(int i=0; i<n; i++)
    {
        int maxl = 1;
        subsequence(i, i+1, n, arr, 1, maxl);
        // cout<<arr[i]<<" "<<maxl<<endl;
        maxlen = max(maxlen, maxl);
    }
    cout<<maxlen;
}

///////////////////////////////////////////////OR///////////////////////////////

// METHOD 2 --> O(n^2)
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int maxlen = 1;
    vector<int> len(n,1);
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j >= 0; j--)
            if(arr[j] < arr[i] && len[j] + 1 > len[i])
                len[i] = len[j] + 1;
    }
    for(int j : len)
        maxlen = max(maxlen, j);
    cout<<maxlen;
}