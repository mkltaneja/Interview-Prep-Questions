#include <iostream>
#include <unordered_map>
using namespace std;

int first_nonrepeating_char(string &s)
{
    unordered_map<char, int> m;

    for (char c : s)
        m[c]++;
    for (int i = 0; i < s.size(); i++)
        if (m[s[i]] == 1)
            return i;
    return -1;
}

int main()
{
    string s;
    cin >> s;

    cout << first_nonrepeating_char(s);

    return 0;
}