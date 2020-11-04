
// METHOD 1 --> O(n^2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> idx;
int count_anagrams(string &s1, string &s2)
{
    int count = 0;
    for (int i = 0; i + s2.size() <= s1.size(); i++)
    {
        string tmp = s1.substr(i, s2.size());
        sort(tmp.begin(), tmp.end());
        if (tmp == s2)
        {
            idx.push_back(i);
            count++;
        }
    }
    return count;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    sort(s2.begin(), s2.end());

    cout << count_anagrams(s1, s2) << endl;
    for (int i : idx)
        cout << i << " ";

    return 0;
}

// METHOD 2 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool equal(unordered_map<char, int> &m1, unordered_map<char, int> &m2)
{
    for (auto p : m2)
        if (m1[p.first] != m2[p.first])
            return false;
    return true;
}

vector<int> idx;
int count_anagrams(string &s1, string &s2)
{
    int count = 0;
    unordered_map<char, int> m1, m2;
    for (char c : s2)
        m2[c]++;
    for (int i = 0; i < s1.size(); i++)
    {
        m1[s1[i]]++;
        // cout<<s1[i]<<" ";
        if (i >= s2.size() - 1)
        {
            if (i != s2.size() - 1)
            {
                // cout<<s1[i-s2.size()];
                if (--m1[s1[i - s2.size()]] == 0)
                    m1.erase(s1[i - s2.size()]);
            }
            if (equal(m1, m2))
            {
                count++;
                idx.push_back(i - s2.size() + 1);
            }
        }
        // cout<<endl;
    }
    return count;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << count_anagrams(s1, s2) << endl;
    for (int i : idx)
        cout << i << " ";

    return 0;
}