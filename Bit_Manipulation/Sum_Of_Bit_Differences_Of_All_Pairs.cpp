
// METHOD 1 --> O(n^2)
// TLE
#include<iostream>
using namespace std;

int Kernighan(int n)
{
    int bits = 0;
    while(n)
    {
        bits++;
        n -= n & -n;
    }
    return bits;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int ans = 0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            ans += Kernighan(arr[i] ^ arr[j]);
    cout<<2*ans;
    
    return 0;
}

//////////////////////////////////////////OR////////////////////////////////////

// METHOD 2 --> O(32*n)
// AC
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int maxi = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
    }
    int bits = 0;
    while(maxi)
    {
        bits++;
        maxi /= 2;
    }
    unsigned long ans = 0;
    for(int i=0; i<bits; i++)
    {
        unsigned long mask = (1 << i), ons = 0, offs = 0;
        for(int j=0; j<n; j++)
            if(arr[j] & mask)
                ons++;
            else
                offs++;
        ans += ons * offs;
    }
    cout<<2*ans;
    
    return 0;
}