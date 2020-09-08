#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    if(n == 0 || (n & n-1))
        cout<<"false";
    else
        cout<<"true";
    
    return 0;
}