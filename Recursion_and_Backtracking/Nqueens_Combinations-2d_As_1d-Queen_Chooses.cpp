#include<iostream>
#include<vector>
#define vb vector<bool>
using namespace std;

void nqueen_combi(int idx, int n, vb &col, vb &rdiag, vb &ldiag, vector<vector<char>> &board)
{
    if(idx == n)
    {
        for(vector<char> v : board)
        {
            for(char c : v)
            {
                cout<<c<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int j=0; j<n; j++)
    {
        if(!col[j] && !ldiag[idx+j] && !rdiag[(n-1)-(idx-j)])
        {
            col[j] = 1;
            ldiag[idx+j] = 1;
            rdiag[(n-1) - (idx-j)] = 1;
            board[idx][j] = 'q';
            nqueen_combi(idx+1, n, col, rdiag, ldiag, board);
            col[j] = 0;
            ldiag[idx+j] = 0;
            rdiag[(n-1) - (idx-j)] = 0;
            board[idx][j] = '-';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    vb col(n,false);
    vb rdiag(2*n-1,false);
    vb ldiag(2*n-1,false);
    nqueen_combi(0, n, col, ldiag, rdiag, board);
}