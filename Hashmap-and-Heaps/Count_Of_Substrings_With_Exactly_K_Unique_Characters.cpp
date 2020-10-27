#include <iostream>
#include <unordered_map>
using namespace std;

int count_kuniquechar_substring_fork1(string &s, int unique)
{
    int ans = 0;
    unordered_map<char,int> m;
    for(int i = 0; i < s.size();)
    {
        m[s[i]]++;
        if(m.size() == 2)
        {
            m.erase(s[i--]);
            ans += m[s[i]]*(m[s[i]] + 1)/2;
            m.erase(s[i]);
        }
        i++;
    }
    ans += m[s[s.size()-1]]*(m[s[s.size()-1]] + 1)/2;
    return ans;
}

int count_kuniquechar_substring(string &s, int unique)
{
    if(unique == 1)
        return count_kuniquechar_substring_fork1(s, unique);
    unordered_map<char,int> mb, ms;
    int i = -1, j = -1, k = 0;
    int ans = 0;
    
    while(true)
    {
        bool f1 = false, f2 = false, f3 = false;
        while(i+1 < s.size())
        {
            f1 = true;
            mb[s[++i]]++;
            if(mb.size() == unique + 1)
            {
                mb.erase(s[i--]);
                break;
            }
        }
        while(j+1 <= i)
        {
            f2 = true;
            ms[s[++j]]++;
            if(ms.size() == unique)
            {
                ms.erase(s[j--]);
                break;
            }
        }
        while(k <= j)
        {
            f3 = true;
            if(mb.size() == unique && ms.size() == unique-1)
                ans += i - j;
            if(--mb[s[k]] == 0)
                mb.erase(s[k]);
            if(--ms[s[k]] == 0)
                ms.erase(s[k]);
            k++;
            if(mb.size() < unique || ms.size() < unique-1)
                break;
        }
        
        if(!f1 && !f2 && !f3)
            break;
    }
    
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << count_kuniquechar_substring(s, k);
}