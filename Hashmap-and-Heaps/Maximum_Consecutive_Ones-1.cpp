#include <iostream>
#include <vector>
using namespace std;

int maxconsec_ones(int n, vector<int> &arr)
{
    int maxones = 0;
    int preones = 0, postones = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            if (flag)
                postones++;
            else
                preones++;
        }
        else
        {
            if (!flag)
                flag = true;
            else
            {
                maxones = max(maxones, preones + 1 + postones);
                preones = postones;
                postones = 0;
            }
        }
    }
    maxones = max(maxones, preones + 1 + postones);
    return !flag ? maxones - 1 : maxones;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxconsec_ones(n, arr);

    return 0;
}