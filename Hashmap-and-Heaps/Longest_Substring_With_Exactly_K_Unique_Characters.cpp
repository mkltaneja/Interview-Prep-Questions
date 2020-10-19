#include <iostream>
#include <unordered_map>
using namespace std;

int longest_kuniquechar_substring(string &s, int k)
{
    int maxlen = 0;
    unordered_map<char, int> freq;
    int i = 0, end = 0;
    for (char c : s)
    {
        freq[c]++;
        if (freq.size() == k)
            maxlen = max(maxlen, end - i + 1);
        while (freq.size() > k)
        {
            if (--freq[s[i]] == 0)
                freq.erase(s[i]);
            i++;
        }
        end++;
    }
    return maxlen;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << longest_kuniquechar_substring(s, k);
}