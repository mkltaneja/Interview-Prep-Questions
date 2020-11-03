#include <iostream>
#include <unordered_map>
using namespace std;

int count_atmost_kuniquechar_substrings(string &s, int k)
{
    unordered_map<char, int> m;
    int count = 0, j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
        while (j <= i && m.size() > k)
        {
            if (--m[s[j]] == 0)
                m.erase(s[j]);
            j++;
        }
        count += i - j + 1;
    }

    return count;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << count_atmost_kuniquechar_substrings(s, k);

    return 0;
}