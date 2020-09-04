#include<iostream>
using namespace std;
int main()
{
    int n, ans = 0, num;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        ans ^= num;
    }
    cout<<ans<<endl;
    
    return 0;
}