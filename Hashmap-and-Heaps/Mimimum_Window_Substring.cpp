#include <iostream>
#include <unordered_map>
using namespace std;

string smallest_allchar_substring(string &s, string &t, int count, unordered_map<char, int> &mt)
{
    if (s == "" || t == "")
        return "";
    int matched = 0;
    unordered_map<char, int> mc;

    string ans = "", minans = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        mc[s[i]]++;
        if (mc[s[i]] <= mt[s[i]])
            matched++;
        while (matched == count)
        {
            ans = s.substr(j, (i - j + 1));
            // cout<<ans<<endl;
            if (minans.size() == 0 || ans.size() < minans.size())
                minans = ans;
            // cout<<s[j]<<": "<<mc[s[j]]<<" --> ";
            if (--mc[s[j]] == 0)
                mc.erase(s[j]);
            if (mc[s[j]] < mt[s[j]])
                matched--;
            // cout<<mc[s[j]]<<endl;
            j++;
        }
    }
    return minans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> mt;
    for (char c : t)
        mt[c]++;
    // for(auto c : mt)
    //     cout<<c.first<<" "<<c.second<<endl;
    cout << smallest_allchar_substring(s, t, t.size(), mt) << endl;

    return 0;
}