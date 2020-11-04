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