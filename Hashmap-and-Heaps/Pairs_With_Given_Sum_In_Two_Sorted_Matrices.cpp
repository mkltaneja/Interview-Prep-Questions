#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int total_pairs(int n, vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[mat1[i][j]]++;

    int pairs = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pairs += m[x - mat2[i][j]];

    return pairs;
}

int main()
{
    int n, x;
    cin >> n;
    vector<vector<int>> mat1(n, vector<int>(n)), mat2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat2[i][j];
    cin >> x;

    cout << total_pairs(n, mat1, mat2, x);

    return 0;
}