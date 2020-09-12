
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