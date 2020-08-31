
// (QUEEN WISE)

#include<iostream>
#include<vector>
using namespace std;

void queen_permu(int placed, int n, vector<vector<char>> &board)
{
    if(placed == n+1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                board[i][j] == '-' ? cout<<board[i][j]<<"\t" : cout<<'q'<<board[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j] == '-')
            {
                board[i][j] = (char)(placed + '0');
                queen_permu(placed+1, n, board);
                board[i][j] = '-';
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            board[i][j] = '-';
    queen_permu(1, n, board);
}