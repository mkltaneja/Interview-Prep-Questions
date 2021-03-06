
// NETHOD 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int equivalent_subarrays(int n, vector<int> &arr, int unique)
{
    unordered_map<int, int> mb, ms;
    int i = -1, j = -1, k = 0;
    int ans = 0;

    while (true)
    {
        bool f1 = false, f2 = false, f3 = false;
        while (i + 1 < n)
        {
            f1 = true;
            mb[arr[++i]]++;
            if (mb.size() == unique + 1)
            {
                mb.erase(arr[i--]);
                break;
            }
        }
        while (j + 1 < i)
        {
            f2 = true;
            ms[arr[++j]]++;
            if (ms.size() == unique)
            {
                ms.erase(arr[j--]);
                break;
            }
        }
        while (k < j)
        {
            f3 = true;
            if (mb.size() == unique && ms.size() == unique - 1)
                ans += i - j;
            if (--mb[arr[k]] == 0)
                mb.erase(arr[k]);
            if (--ms[arr[k]] == 0)
                ms.erase(arr[k]);
            k++;
            if (mb.size() < unique || ms.size() < unique - 1)
                break;
        }

        if (!f1 && !f2 && !f3)
            break;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    cout << equivalent_subarrays(n, arr, st.size());

    return 0;
}

// METHOD 2
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int equivalent_subarrays(int n, vector<int> &arr, int k)
{
    unordered_map<int, int> m;
    int j = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        while (m.size() == k)
        {
            ans += arr.size() - i;
            if (--m[arr[j]] == 0)
                m.erase(arr[j]);
            j++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    cout << equivalent_subarrays(n, arr, st.size());

    return 0;
}