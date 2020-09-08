#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c = a ^ b;
    int count = 0;
    while(c)
    {
        count++;
        c -= c & -c;
    }
    cout<<count;
    
    return 0;
}