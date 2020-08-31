
// METHOD 1 (using 2d board)
#include<iostream>
#include<vector>
using namespace std;

void queen_combi(int idx, int placed, int n, vector<vector<char>> &board)
{
    if(idx == n*n)
    {
        if(placed == n)
        {
            for(vector<char> v : board)
            {
                for(char c : v)
                {
                    cout<<c;
                }
                cout<<endl;
            }
            cout<<endl;
        }
        return;
    }
    int r = idx / n;
    int c = idx % n;
    
    board[r][c] = 'q';
    queen_combi(idx+1, placed+1, n, board);
    board[r][c] = '-';
    
    queen_combi(idx+1, placed, n, board);
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            board[i][j] = '-';
    queen_combi(0, 0, n, board);
}

////////////////////////////////////OR/////////////////////////////////

// METHOD 2 (using string)

#include<iostream>
#include<vector>
using namespace std;

void queen_combi(int row, int col, int placed, int n, string ans)
{
    if(row == n)
    {
        if(placed == n)
            cout<<ans<<endl;
        return;
    }
    
    int nr = 0, nc = 0;
    string yssf = "", nssf = "";
    if(col == n-1)
    {
        nr = row + 1;
        nc = 0;
        yssf = ans + "q\n";
        nssf = ans + "-\n";
    }
    else
    {
        nr = row;
        nc = col + 1;
        yssf = ans + "q";
        nssf = ans + "-";
    }
    queen_combi(nr, nc, placed+1, n, yssf);
    queen_combi(nr, nc, placed, n, nssf);
}

int main()
{
    int n;
    cin>>n;
    
    queen_combi(0, 0, 0, n, "");
}