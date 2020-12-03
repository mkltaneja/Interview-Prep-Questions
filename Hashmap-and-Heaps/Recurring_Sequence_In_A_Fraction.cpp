#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string fraction(int n, int d)
{
    string frac = "";
    unordered_map<int,int> m;  // index(in string), quotient
    int rem = -1;
    if(d > n)
    {
        frac += "0.";
        rem = n;
        n *= 10;
        while(d > n)
        {
            n *= 10;
            frac += "0";
        }
    }
    else
    {
        frac += to_string(n / d);
        rem = n % d;
        n = rem;
        n *= 10;
        if(rem != 0)
            frac += ".";
    }
    
    while(rem != 0)
    {
        if(m.find(rem) != m.end())
        {
            frac.insert(m[rem], "(");
            frac += ")";
            break;
        }
        m.insert({rem,frac.size()});
        frac += to_string(n / d);
        rem = n % d;
        n = rem;
        n *= 10;
        while(d > n)
        {
            n *= 10;
            frac += "0";
        }
        // cout<<rem<<endl;
    }
    
    return frac;
}

int main()
{
    int n, d;
    cin>>n>>d;
    
    cout<<fraction(n, d);
}