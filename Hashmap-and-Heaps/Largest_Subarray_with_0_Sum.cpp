#include <iostream>
#include <vector>
#include <map>
#define f first
#define s second
using namespace std;

bool check_pair(int k, map<int, int> &modk)
{
    for (auto itr : modk)
    {
        if (itr.f == 0 && itr.s % 2 != 0)
            return false;
        else if (itr.f == k / 2 && itr.s % 2 != 0)
            return false;
        else if (itr.f != 0 && itr.f != k / 2 && itr.s != modk[k - itr.f])
            return false;
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    map<int, int> modk;
    for (int i = 0; i < n; i++)
        modk[arr[i] % k]++;

    cout << (boolalpha) << check_pair(k, modk);

    return 0;
}