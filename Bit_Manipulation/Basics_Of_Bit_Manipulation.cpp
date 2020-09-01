#include<iostream>
#include<climits>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n = (1 << 31);
    n--;
    // cout<<n-1<<endl;
    // n >>= 1;
    string bin = "";
    string last = "";
    while(n > 0)
    {
        bin += to_string(n % 2);
        cout<<bin<<endl;
        n >>= 1;
    }
    // reverse(bin.begin(), bin.end());
    // cout<<bin;
    // int n, i, j, k, m;
    // cin>>n>>i>>j>>k>>m;
    // int mask1 = (1 << i);
    // int mask2 = (1 << j);
    // int mask3 = (1 << k);
    // int mask4 = (1 << m);
    // cout<<(n | mask1)<<endl;
    // cout<<(n & ~mask2)<<endl;
    // cout<<(n ^ mask3)<<endl;
    // cout<<(boolalpha)<<((n & mask4) > 0)<<endl;
}