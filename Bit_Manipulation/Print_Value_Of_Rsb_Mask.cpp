
// METHOD 1 --> O(32)

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s = "";
    int mask = 1;
    while(((n & mask) == 0) && (mask <= (1 << 30)))
    {
        s += "0";
        mask <<= 1;
    }
    s += "1";
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

///////////////////////////////////////////OR///////////////////////

// METHOD 1 --> O(1)

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num = -n;  // 2's Complement
    num = (num & n);
    string binary = "";
    while(num)
    {
        binary += (num & 1) + '0';
        num >>= 1;
    }
    reverse(binary.begin(), binary.end());
    cout<<binary<<endl;
}