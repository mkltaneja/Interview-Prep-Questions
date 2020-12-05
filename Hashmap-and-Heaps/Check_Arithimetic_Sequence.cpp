#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

bool is_AP(int n, vector<int> &arr)
{
    if (n == 1)
        return true;
    unordered_set<int> s;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i : arr)
    {
        mini = min(mini, i);
        maxi = max(maxi, i);
        s.insert(i);
    }
    int cd = (maxi - mini) / (n - 1);

    for (int i = 0; i < n; i++)
    {
        int ai = mini + i * cd;
        if (s.find(ai) == s.end())
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (boolalpha) << is_AP(n, arr);

    return 0;
}