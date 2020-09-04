
// METHOD 1 --> O(n^3)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int count = 0;
    for(int cut = 1; cut < n; cut++)
    {
        int left = 0;
        for(int l = cut-1; l >= 0; l--)
        {
            // cout<<arr[l]<<" -> ";
            left ^= arr[l];
            int right = 0;
            for(int r = cut; r < n; r++)
            {
                // cout<<arr[r]<<", ";
                right ^= arr[r];
                count += (left == right);
            }
            // cout<<endl;
        }
    }
    cout<<count;
}

/////////////////////////////////////////////OR///////////////////////////////////

// METHOD 2 --> O(n^2)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int count = 0;
    for(int i=0; i<n; i++)
    {
        int xord = arr[i];
        for(int k=i+1; k<n; k++)
        {
            xord ^= arr[k];
            if(xord == 0)
                count += k-i;
        }
    }
    cout<<count;
}