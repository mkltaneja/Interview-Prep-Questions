#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void anagram_mapping(int n, vector<int> &a, vector<int> &b)
{
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[b[i]].push_back(i);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = m[a[i]].front();
        m[a[i]].erase(m[a[i]].begin());
    }

    for (int i : ans)
        cout << i << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    anagram_mapping(n, a, b);
}