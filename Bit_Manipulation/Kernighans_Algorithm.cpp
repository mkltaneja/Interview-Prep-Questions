
// APPROACH 1 (naive)

#include<iostream>
using namespace std;
int main()
{
    long n;
    cin>>n;
    int count = 0;
    while(n)
    {
        if(n & 1)
            count++;
        n >>= 1;
    }
    cout<<count<<endl;
    return 0;
}


/////////////////////////////////////////OR/////////////////////////////////

// APPROACH 2 (Reducing by righmost significant bit)

#include<iostream>
using namespace std;
int main()
{
    long n;
    cin>>n;
    int count = 0;
    while(n)
    {
        int rmsb = -n;
        rmsb &= n;
        n -= rmsb;
        count++;
    }
    cout<<count<<endl;
    return 0;
}