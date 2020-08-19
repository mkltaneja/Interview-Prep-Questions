#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<int> a(n,0);
        for(int i = 0; i < n; i++)
            cin>>a[i];

        long long int sum = 0, maxsum = 0;
        for(int i=0; k; i = (i+1)%n)
        {
            sum += a[i];
            maxsum = max(maxsum, sum);
            if(sum < 0)
                sum = 0;
            if(i == n-1)
                k--;
        }
        cout<<maxsum<<endl;
    }
}