#include <iostream>
#include <unordered_set>
#include <climits>
using namespace std;

void all_substrings(int p, int &maxi, string &s, unordered_set<int> &subs)
{
    for (int idx = s.size() - 1; idx >= 0; idx--)
    {
        int num = 0;
        for (int i = idx; i < s.size(); i++)
        {
            num = (num * 2) + (s[i] - '0');
            subs.insert(num);
        }
        maxi = max(maxi, num);
    }
}

bool Solution(string &s, int m, int n)
{
    if (m * m < n)
        return false;
    unordered_set<int> subs;

    int maxi = INT_MIN;
    all_substrings(1, maxi, s, subs);
    // cout<<maxi<<endl;
    // for(int i : subs)
    //     cout<<i<<" ";

    for (int num = 1; num <= n; num++)
        if (subs.find(num) == subs.end())
            return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int m = s.size();

    cout << (boolalpha) << Solution(s, m, n);
}