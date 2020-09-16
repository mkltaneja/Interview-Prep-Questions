
// METHOD 1 
// TLE
#include<iostream>
#include<algorithm>
using namespace std;

bool ispalindrome(string s)
{
    int i = 0, j = s.size()-1;
    while(i < j)
        if(s[i++] != s[j--])
            return false;
    return true;
}

string numtobin(int num)
{
    string s = "";
    while(num)
    {
        s += (num % 2) + '0';
        num >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int n;
    cin>>n;
    unsigned long long int num = 0;
    while(n)
    {
        num++;
        if(ispalindrome(numtobin(num)))
            n--;
    }
    cout<<num;
    return 0;
}

// METHOD 2
// AC
#include<iostream>
using namespace std;

int reversebits(int n, int msbpos)
{
    int revans = 0, j = 0;
    bool f = false;
    for(int i=31; i>=0; i--)
    {
        int mask1 = (1 << i);
        int mask2 = (1 << j);
        if(n & mask1)
        {
            f = true;
            revans |= mask2;
        }
        if(f)
            j++;
    }
    return revans;
}

int main()
{
    int n;
    cin>>n;
    
    int offset = 1, len = 1, size = 1;
    while(offset + size <= n)
    {
        offset += size;
        size = (1 << ((++len)-1)/2);
    }
    int diff = n - offset;
    int ans = (1 << len-1);
    ans |= (diff << (len/2));
    int revans = (ans >> (len/2));
    revans = reversebits(revans,len);
    ans |= revans;
    
    cout<<ans;
        
    return 0;
}