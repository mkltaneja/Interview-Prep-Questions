#include <iostream>
#include <vector>
#include <unordered_map>
#define f first
#define s second
using namespace std;

bool check_pair(int k, unordered_map<int, vector<int>> &modk)
{
    for (auto itr : modk)
    {
        while (modk[itr.f].size() > 0)
        {
            if (modk[k - itr.f].size() == 0)
                return false;
            modk[k - itr.f].pop_back();
        }
    }
    return true;
}

int main()
{
    int n, k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    unordered_map<int, vector<int>> modk;
    for (int i = 0; i < n; i++)
        modk[arr[i] % k].push_back(arr[i]);

    cout << (boolalpha) << check_pair(k, modk);

    return 0;
}