#include<iostream>
#include<vector>
using namespace std;

void queen_combi(int r, int c, int placed, int n, vector<vector<char>> &board)
{
    if(placed == n)
    {
        for(vector<char> v : board)
        {
            for(char ch : v)
                cout<<ch<<"\t";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
        
    for(int j=c; j<n; j++)
    {
        board[r][j] = 'q';
        queen_combi(r, j+1, placed+1, n, board);
        board[r][j] = '-';
    }
    for(int i=r+1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[i][j] = 'q';
            queen_combi(i, j+1, placed + 1, n, board);
            board[i][j] = '-';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n,vector<char>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            board[i][j] = '-';
    queen_combi(0, 0, 0, n, board);
}