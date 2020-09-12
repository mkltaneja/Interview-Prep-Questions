
// METHOD 1
#include<iostream>
using namespace std;

int smallerpower(int n)
{
    int a = 1;
    while(a*2 <= n)
        a <<= 1;
    return a;
}

int main()
{
    int n;
    cin>>n;
    
    int smp = smallerpower(n);
    int num = smp-1, bits = 0;
    while(num)
    {
        num -= num & -num;
        bits++;
    }
    int ans = bits*(smp/2) + 1;
    
    for(int i=smp+1; i<=n; i++)
    {
        int num = i, count = 0;
        while(num)
        {
            num -= num & -num;
            count++;
        }
        ans += count;
    }
    cout<<ans;
    
    return 0;
}

///////////////////////////////////////////////////OR///////////////////////////////////////////

// METHOD 2 (Optimized) --> Optimizing the time to calculate on bits of numbers more than pow(2,p) by recursion
#include<iostream>
using namespace std;

int smallerpower(int n)
{
    int p = 0;
    while((1 << p) <= n)
        p++;
    return p-1;
}

int Solution(int n)
{
    if(n == 0)
        return 0;
    int p = smallerpower(n);
    int onbits_lessthan_2powp = p * (1 << (p-1));
    int on_msbbits_morethan_2powp = n - (1 << (p)) + 1;
    int nums_morethan_2powp = n - (1 << (p));
    
    int ans = onbits_lessthan_2powp + on_msbbits_morethan_2powp + Solution(nums_morethan_2powp);
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<Solution(n);
    return 0;
}