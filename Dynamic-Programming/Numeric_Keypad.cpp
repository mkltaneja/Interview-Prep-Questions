#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}};
int numeric_keypad(int n, vector<vector<int>> &keypad)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            keypad[i][j] = ((i == 3 && j == 0) || (i == 3 && j == 2)) ? 0 : 1;
    while (--n)
    {
        vector<vector<int>> nkeypad(4, vector<int>(3, 0));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i == 3 && j == 0) || (i == 3 && j == 2))
                    continue;
                for (int d = 0; d < 5; d++)
                {
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];
                    if (r < 4 && c < 3 && r >= 0 && c >= 0 && (r != 3 || c != 0) && (r != 3 || c != 2))
                        nkeypad[i][j] += keypad[r][c];
                }
            }
        }
        keypad = nkeypad;
    }
    int count = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            count += keypad[i][j];
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> keypad(4, vector<int>(3, 0));
    cout << numeric_keypad(n, keypad);
}