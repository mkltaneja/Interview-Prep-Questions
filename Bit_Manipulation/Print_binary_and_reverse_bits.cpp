#include<iostream>
#include<algorithm>
using namespace std;

string numtobin(int n)
{
    string s = "";
    while(n)
    {
        s += (n % 2) + '0';
        n >>= 1;
    }
    return s;
}

int bintonum(string s)
{
    int ans = 0;
    for(char c : s)
        ans = ans*2 + (c - '0');
    return ans;
}

int main()
{
    int n;
    cin>>n;
    string s = numtobin(n);
    int num = bintonum(s);
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    cout<<num;
    return 0;
}