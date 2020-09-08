#include<iostream>
using namespace std;
int main()
{
    int a, b, l, r;
    cin>>a>>b>>l>>r;
    int diff = (1 << (r-l+1));
    diff--;
    diff <<= l-1;
    int num = a & diff;
    num = b | num;
    cout<<num;
    
    return 0;
}