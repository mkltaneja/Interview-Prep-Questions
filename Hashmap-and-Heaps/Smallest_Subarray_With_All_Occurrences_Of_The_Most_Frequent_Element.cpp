#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#define f first
#define s second
using namespace std;

int final_mostfreq(vector<int> &arr, unordered_set<int> &mins)
{
    for (int i : arr)
        if (mins.find(i) != mins.end())
            return i;
    return -1;
}

int mostfreq(int n, vector<int> &arr, unordered_set<int> &mfs)
{
    unordered_map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
        if (mfs.find(arr[i]) != mfs.end())
            m[arr[i]].s = i; // last occurence of every mf
    for (int i = n - 1; i >= 0; i--)
        if (mfs.find(arr[i]) != mfs.end())
            m[arr[i]].f = i; // first occurence of every mf

    int minsize = INT_MAX;
    unordered_set<int> mins;
    for (auto itr : m)
    {
        if (itr.s.s - itr.s.f < minsize)
        {
            mins.clear();
            minsize = itr.s.s - itr.s.f;
            mins.insert(itr.f);
        }
        else if (itr.s.s - itr.s.f == minsize)
            mins.insert(itr.f);
    }
    return final_mostfreq(arr, mins);
}

void most_freq_element(int n, vector<int> &arr)
{
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;

    int maxcount = 0;
    unordered_set<int> mfs;
    for (auto itr : m)
    {
        if (itr.second > maxcount)
        {
            mfs.clear();
            maxcount = itr.second;
            mfs.insert(itr.first);
        }
        else if (itr.second == maxcount)
            mfs.insert(itr.first);
    }
    int mf = mostfreq(n, arr, mfs);
    cout << mf << endl;

    int fo = -1, lo = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == mf)
        {
            if (fo == -1)
                fo = i;
            lo = i;
        }
    }
    cout << fo << endl
         << lo << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    most_freq_element(n, arr);
}