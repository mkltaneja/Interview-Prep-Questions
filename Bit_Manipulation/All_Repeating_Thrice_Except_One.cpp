#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n, maxi = INT_MIN;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
    }
    int bits = 0;
    while(maxi)
    {
        maxi /= 2;
        bits++;
    }
    
    int once = 0;
    for(int i=0; i<bits; i++)
    {
        int mask = (1 << i);
        int onbits = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] & mask)
                onbits++;
        }
        if(onbits % 3 == 1)
            once ^= mask;
    }
    cout<<once;
    
    return 0;
}