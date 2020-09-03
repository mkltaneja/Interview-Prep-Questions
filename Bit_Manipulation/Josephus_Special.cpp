
// METHOD 1 (recursion)
// TLE
#include<iostream>
using namespace std;

int josephus(int n)
{
    if(n == 1)
        return 1;
    int lucky = josephus(n-1);
    return (lucky+2) == n ? n : (lucky + 2) % n ;
}

int main()
{
    int n;
    cin>>n;
    cout<<josephus(n);
    return 0;
}

//////////////////////////////////////////OR////////////////////////////

// METHOD 2 (Using BITS Manipulation)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num = 1;
    while(num*2 <= n)
        num *= 2;
    int l = n - num;
    cout<<(2*l + 1);
    return 0;
}