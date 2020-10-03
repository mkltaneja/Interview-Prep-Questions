#include<iostream>
#include<algorithm>
#include<vector>
#define f first
#define s second
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i].f>>arr[i].s;
    
    sort(arr.begin(), arr.end());
    
    vector<int> len(n,1);
    int maxlen = 1;
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j].s < arr[i].s && len[j]+1 > len[i])
                len[i] = len[j] + 1, maxlen = max(maxlen, len[i]);
    
    cout<<maxlen;
    
    return 0;
}