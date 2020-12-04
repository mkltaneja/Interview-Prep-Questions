
// METHOD 1 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int rabbits_in_forest(int n, vector<int> &arr)
{
    int count = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (m[x] == 0)
        {
            m[x] = x;
            count += x + 1;
        }
        else
            m[x]--;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << rabbits_in_forest(n, arr);

    return 0;
}

// METHOD 2 (Derived from METHOD 1)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int rabbits_in_forest(int n, vector<int> &arr)
{
    int count = 0;
    unordered_map<int, int> m;

    for (int x : arr)
        m[x]++;

    for (auto itr : m)
    {
        int rabs = itr.first + 1;
        int grps = ceil(1.0 * itr.second / rabs);
        count += grps * rabs;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << rabbits_in_forest(n, arr);

    return 0;
}