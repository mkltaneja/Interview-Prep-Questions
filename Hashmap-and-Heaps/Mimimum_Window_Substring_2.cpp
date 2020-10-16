#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int smallest_allchar_substring(string &s, int count, unordered_map<char, int> &mu)
{
    if (s == "")
        return 0;
    int matched = 0;
    unordered_map<char, int> mc;

    int ans = 0, minans = INT_MAX;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mc[s[i]]++;
        if (mc[s[i]] <= mu[s[i]])
            matched++;
        while (matched == count)
        {
            ans = i - j + 1;

            minans = min(minans, ans);
            if (--mc[s[j]] == 0)
                mc.erase(s[j]);
            if (mc[s[j]] < mu[s[j]])
                matched--;
            j++;
        }
    }
    return minans;
}

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mu;
    for (char c : s)
        mu[c] = 1;
    // for(auto c : mu)
    //     cout<<c.first<<" "<<c.second<<endl;
    cout << smallest_allchar_substring(s, mu.size(), mu) << endl;

    return 0;
}