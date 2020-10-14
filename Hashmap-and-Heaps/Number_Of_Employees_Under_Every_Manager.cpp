#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#define f first
#define s second
using namespace std;

int traverse(string ceo, unordered_map<string, vector<string>> &tree, map<string, int> &ans)
{
    for (string child : tree[ceo])
    {
        ans[ceo] += traverse(child, tree, ans) + 1;
    }
    return ans[ceo];
}

void Solution(int n, vector<pair<string, string>> &vp)
{
    string ceo;
    unordered_map<string, vector<string>> tree;
    for (auto p : vp)
    {
        if (p.f == p.s)
            ceo = p.f;
        else
            tree[p.s].push_back(p.f);
    }
    map<string, int> ans;
    traverse(ceo, tree, ans);
    for (auto p : ans)
        cout << p.f << " " << p.s << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, string>> vp(n);
    for (int i = 0; i < n; i++)
        cin >> vp[i].f >> vp[i].s;

    Solution(n, vp);
}