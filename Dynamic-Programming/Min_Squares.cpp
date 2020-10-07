
// METHOD 1 (Recursive)
#include<iostream>
#include<climits>
using namespace std;

int minsquares(int n)
{
    if(n == 0)
        return 0;
    int minans = INT_MAX;
    for(int i = 1; i*i <= n; i++)
        minans = min(minans, minsquares(n - i*i) + 1);
    return minans;
}

int main()
{
    int n;
    cin>>n;
    cout<<minsquares(n);
    
    return 0;
}