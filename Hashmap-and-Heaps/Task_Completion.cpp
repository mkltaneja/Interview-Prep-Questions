#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void task_completion(int n, int m, vector<int> &arr)
{
    unordered_set<int> s;
    for (int i : arr)
        s.insert(i);
    int turn = 1;
    vector<int> s1, s2;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            if (turn == 1)
                s1.push_back(i);
            else
                s2.push_back(i);
            turn = (turn + 1) % 2;
        }
    }

    for (int i : s1)
        cout << i << " ";
    cout << endl;
    for (int i : s2)
        cout << i << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    task_completion(n, m, arr);

    return 0;
}