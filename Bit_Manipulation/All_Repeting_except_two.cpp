#include<iostream>
using namespace std;
int main()
{
    int n, diffs = 0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        diffs ^= arr[i];
    }
    
    int rsb = (diffs & -diffs);
    
    int onbit = 0, offbit = 0;
    for(int i : arr)
    {
        if(i & rsb)
            onbit ^= i;
        else
            offbit ^= i;
    }
    cout<<min(onbit,offbit)<<endl<<max(onbit,offbit);
    
    return 0;
}