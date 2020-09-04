
// METHOD 1 (USING COMBINATIONS - by subsequence)
// TLE

#include<iostream>
#include<algorithm>
using namespace std;

string dectobin(long n)
{
    string s = "";
    while(n)
    {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

long bintodec(string &s)
{
    cout<<s<<" -> ";
    long ans = 0, t = 1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        ans += t * (s[i] - '0');
        t *= 2;
    }
    cout<<ans<<endl;
    return ans;
}

int combinations(int ones, int tones, long n, int len, string ans)
{
    if(ans.size() == len)
    {
        if(ones == tones)
            if(bintodec(ans) < n)
                return 1;
        return 0;
    }
    int count = 0;
    count += combinations(ones+1, tones, n, len, ans + "1");
    count += combinations(ones, tones, n, len, ans + "0");
    
    return count;
}

int main()
{
    long n;
    cin>>n;
    string bin = dectobin(n);
    int ones = 0;
    for(char c : bin)
        if(c == '1')
            ones++;
    cout<<combinations(0, ones, n, bin.size(), "");
}

//////////////////////////////////////OR//////////////////////////////

// METHOD 2 (Using Combinations Formula)

#include<iostream>
using namespace std;

long int countzeros(long int n)
{
    long int count = 0;
    while(n != 1)
    {
        count++;
        n /= 2;
    }
    return count;
}

long int C(long int n, long int r)
{
    if(n < r)
        return 0;
    if(n == r || n == 1)
        return 1;
    
    r = min(r, n-r);
    long int ans = 1, i = 0;
    while(i < r)
    {
        ans *= n-i;
        ans /= ++i;
    }
        
    return ans;
}

int main()
{
    long int n;
    cin>>n;
    
    long int ans = 0, ones = 1;
    while(n)
    {
        long int rsb = (n & -n);
        long int zeros = countzeros(rsb);
        ans += C(zeros, ones++);
        n -= rsb;
    }
    cout<<ans;
    
    return 0;
}