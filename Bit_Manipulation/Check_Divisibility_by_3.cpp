#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    reverse(s.begin(), s.end());
    int n = s.size(), ones = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '1')
        {
            if(i & 1)
                ones++;
            else
                ones--;
        }
    }
    if(ones % 3 == 0)
        cout<<"true";
    else
        cout<<"false";
        
    return 0;
}