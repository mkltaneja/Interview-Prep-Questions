
// METHOD 1 (Using 2 Hashmaps)
#include<iostream>
#include<unordered_map>
using namespace std;

bool isvalid_anagram(string &s1, string &s2)
{
    if(s1.size() != s2.size())
        return false;
    unordered_map<char,int> m1, m2;
    for(char c : s1)
        m1[c]++;
    for(char c : s2)
        m2[c]++;
    if(m1.size() != m2.size())
        return false;
        
    for(auto itr : m1)
        if(m2[itr.first] != itr.second)
            return false;
        
    return true;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    cout<<(boolalpha)<<isvalid_anagram(s1, s2);
    
    return 0;
}

// METHOD 2 (Using 1 Hashmap)
#include<iostream>
#include<unordered_map>
using namespace std;

bool isvalid_anagram(string &s1, string &s2)
{
    if(s1.size() != s2.size())
        return false;
    unordered_map<char,int> m;
    for(char c : s1)
        m[c]++;
    for(char c : s2)
        if(--m[c] == 0)
            m.erase(c);
    return m.size() == 0;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    cout<<(boolalpha)<<isvalid_anagram(s1, s2);
    
    return 0;
}