#include<iostream>
#include<unordered_map>
using namespace std;

bool is_Kanagram(string &s1, string &s2, int k)
{
    if(s1.size() != s2.size())
        return false;
    unordered_map<char,int> m;
    for(char c : s1)
        m[c]++;
    for(char c : s2)
        if(m[c] > 0)
            m[c]--;
    int diff = 0;
    for(auto p : m)
        diff += (p.second);
    return diff <= k;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int k;
    cin>>k;
    
    cout<<(boolalpha)<<is_Kanagram(s1, s2, k);
}