#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num = n;
    num <<= 3;
    num -= n;
    num >>= 3;
    cout<<num;
    
    return 0;
}