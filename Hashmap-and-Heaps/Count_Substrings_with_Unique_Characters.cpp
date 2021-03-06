
// METHOD 1 (using set)
#include <iostream>
#include <unordered_set>
using namespace std;

int count_uniquechar_substrings(string &s)
{
    unordered_set<int> vis;
    int count = 0;
    int i = 0, end = 0, pend = -1;
    for (char c : s)
    {
        if (vis.find(c) != vis.end())
        {
            count += ((end - i) * (end - i + 1) / 2) - ((pend - i + 1) * (pend - i + 2) / 2);
            while (s[i] != c)
                vis.erase(s[i++]);
            vis.erase(s[i++]);
            pend = end - 1;
        }
        vis.insert(c);
        end++;
    }
    count += ((end - i) * (end - i + 1) / 2) - ((pend - i + 1) * (pend - i + 2) / 2);
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << count_uniquechar_substrings(s);
}

// METHOD 2 (using map)
#include <iostream>
#include <unordered_map>
using namespace std;

int count_uniquechar_substrings(string &s)
{
    unordered_map<char, int> freq;
    int count = 0;
    int i = 0, end = 0;
    for (char c : s)
    {
        freq[c]++;
        while (freq[c] == 2)
            freq[s[i++]]--;
        count += end++ - i + 1;
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    cout << count_uniquechar_substrings(s);
}