#include<iostream>
#include<vector>
#include<algorithm>
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
        
    vector<int> maxnono(n,1);
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j].f <= arr[i].f && arr[j].s <= arr[i].s && maxnono[j]+1 > maxnono[i])
                maxnono[i] = maxnono[j] + 1;
    int maxans = 1;
    for(int i : maxnono)
        maxans = max(maxans, i);
    cout<<maxans;
    
    return 0;
}