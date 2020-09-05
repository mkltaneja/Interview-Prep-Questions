#include<iostream>
using namespace std;

bool isUTF8(int n, int arr[])
{
    for(int i=0; i<n; i++)
    {
        int mask = (1 << 7);
        int counto = 0;
        while(arr[i] & mask)
        {
            counto++;
            mask >>= 1;
        }
        while(--counto > 0)
        {
            if(++i == n)
                return false;
            if(((1 << 7) & arr[i]) == 0 || ((1 << 6) & arr[i]) != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    cout<<(boolalpha)<<isUTF8(n, arr);
}

/////////////////////////////////////////////OR/////////////////////////////////////

#include<iostream>
#include<vector>
using namespace std;

bool isUTF8(int n, vector<int> &arr)
{
    int counto = 0;
    for(int num : arr)
    {
        if(counto == 0)
        {
            if((num >> 7) == 0b0)  //(0b represents binary(after this) like 0x for hexadecimal)
                counto = 0;
            else if((num >> 5) == 0b110)
                counto = 1;
            else if((num >> 4) == 0b1110)
                counto = 2;
            else if((num >> 3) == 0b11110)
                counto = 3;
            else
                return false;
        }
        else
        {
            if((num >> 6) == 0b10)
                counto--;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    cout<<(boolalpha)<<isUTF8(n, arr);
}