#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int nn = n, count = 0;
    while(nn)
    {
        count++;
        nn /= 2;
    }
    int odd = 0, even = 0;
    for(int i=0; i<count; i++)
    {
        int mask = (1 << i);
        if((i & 1) && (n & mask))
            even |= mask;
        else if(!(i & 1) && (n & mask))
            odd |= mask;
    }
    even >>= 1, odd <<= 1;
    int ans = even | odd;
    
    cout<<ans<<endl;
    
    return 0;
}

///////////////////////////////////////OR/////////////////////////////////

// METHOD 2 (Different way of declaring even and odd bits)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int nn = n, count = 0;
    while(nn)
    {
        count++;
        nn /= 2;
    }
    int odd = 0x55555555;    // 5 --> 0101     // repeated 8 times 
    int even = 0xAAAAAAAA;   // 10 -> 1010        to get 32 bits
    odd &= n;
    even &= n;
    even >>= 1, odd <<= 1;
    
    int ans = even | odd;
    cout<<ans<<endl;
    
    return 0;
}