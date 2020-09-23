
// APPROACH 1 -- RECURSION --> O(n^n)
#include<iostream>
using namespace std;

bool Wildcard(int i, int j, int n, int m, string s1, string s2)
{
    if(i == n && j == m)
        return true;
    else if(i == n || j == m)
        return false;
    if(s1[i] != s2[j] && (s2[j] != '?' && s2[j] != '*'))
        return false;
    
    bool res = false;
    
    if(s2[j] == '*')
    {
        int k = j+1;
        while(k < m && s2[k] == '*')
            k++;
        if(k == m)
            return true;
        for(int idx=i; idx<n; idx++)
            if(s2[k] == '?' || s1[idx] == s2[k])
                res |= Wildcard(idx, k, n, m, s1, s2);
    }
    else
        res |= Wildcard(i + 1, j + 1, n, m, s1, s2);
    return res;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<(boolalpha)<<Wildcard(0, 0, s1.size(), s2.size(), s1, s2);
}

///////////////////////////////////////////////OR///////////////////////////////////////

// APPROACH -- DP  --> O(n^2)
#include<iostream>
using namespace std;

bool Wildcard(int i, int j, int n, int m, string s1, string s2)
{
    if(i == n && j == m)
        return true;
    else if(i == n || j == m)
        return false;
    if(s1[i] != s2[j] && (s2[j] != '?' && s2[j] != '*'))
        return false;
    
    bool res = false;
    
    if(s2[j] == '*')
    {
        int k = j+1;
        while(k < m && s2[k] == '*')
            k++;
        if(k == m)
            return true;
        for(int idx=i; idx<n; idx++)
            if(s2[k] == '?' || s1[idx] == s2[k])
                res |= Wildcard(idx, k, n, m, s1, s2);
    }
    else
        res |= Wildcard(i + 1, j + 1, n, m, s1, s2);
    return res;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<(boolalpha)<<Wildcard(0, 0, s1.size(), s2.size(), s1, s2);
}