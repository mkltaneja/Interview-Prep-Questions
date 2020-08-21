#include<iostream> 
using namespace std;

void lexorder(int i, int n)
{
    if(i > n)
        return;
        
    cout<<i<<endl;
    for(int num=0; num<=9;num++)
        lexorder(i*10+num, n);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=9; i++)
        lexorder(i,n);
    return 0;
}