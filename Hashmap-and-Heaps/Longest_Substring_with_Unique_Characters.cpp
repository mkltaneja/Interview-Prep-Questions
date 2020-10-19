#include <iostream>
#include <unordered_set>
using namespace std;

int longest_uniquechar_substring(string &s)
{
    int maxlen = 0;
    unordered_set<char> vis;
    int i = 0;
    int size = 0;
    for (char c : s)
    {
        if (vis.find(c) != vis.end())
        {
            // cout<<c<<": \n";
            // cout<<vis.size()<<", "<<s.substr(i)<<" -> ";
            while (s[i] != c)
                vis.erase(s[i++]);
            vis.erase(s[i++]);
            // cout<<vis.size()<<", "<<s.substr(i)<<endl;
        }
        vis.insert(c);
        size = vis.size();
        maxlen = max(maxlen, size);
    }

    return maxlen;
}

int main()
{
    string s;
    cin >> s;
    cout << longest_uniquechar_substring(s);
}