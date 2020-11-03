#include<iostream>
#include<unordered_map>
using namespace std;

int longest_atmost_kuniquechar_substring(string &s, int k)
{
    unordered_map<char,int> m;
    int maxlen = 0, j = 0;
    for(int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
        while(j <= i && m.size() > k)
        {
            if(--m[s[j]] == 0)
                m.erase(s[j]);
            j++;
        }
        maxlen = max(maxlen, i-j+1);
    }
    
    return maxlen;
}

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    
    cout<<longest_atmost_kuniquechar_substring(s, k);
    
    return 0;
}