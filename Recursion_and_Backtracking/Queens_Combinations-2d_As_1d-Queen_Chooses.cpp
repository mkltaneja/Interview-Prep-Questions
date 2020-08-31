#include<iostream>
#include<vector>
using namespace std;

void queen_combi(int idx, int qpsf, int n, vector<vector<char>> &board)
{
    if(qpsf == n)
    {
        for(vector<char> v : board)
        {
            for(char c : v)
                cout<<c<<"\t";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i=idx; i<n*n; i++)
    {
        int r = i / n;
        int c = i % n;
        if(board[r][c] == '-')
        {
            board[r][c] = 'q';
            queen_combi(i+1, qpsf+1, n, board);
            board[r][c] = '-';
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
    queen_combi(0, 0, n, board);
}