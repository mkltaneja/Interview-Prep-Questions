
// QUEEN WISE (but optimized than 2nd method)

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

////////////////////////////////OR/////////////////////////////////

// QUEEN WISE (used one more bool array of row)
#include<iostream>
#include<vector>
#define vb vector<bool>
using namespace std;

void nqueen_combi(int idx, int qpsf, int n, vb &row, vb &col, vb &ldiag, vb &rdiag, vector<vector<char>> &board)
{
    if(qpsf == n)
    {
        for(vector<char> v : board)
        {
            for(char c : v)
            {
                cout<<c<<"	";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=idx; i<n*n; i++)
    {
        int r = i / n;
        int c = i % n;
        if(!row[r] && !col[c] && !ldiag[r+c] && !rdiag[(n-1)+(r-c)])
        {
            row[r] = 1;
            col[c] = 1;
            ldiag[r+c] = 1;
            rdiag[(n-1) + (r-c)] = 1;
            board[r][c] = 'q';
            nqueen_combi(i+1, qpsf+1, n, row, col, ldiag, rdiag, board);
            row[r] = 0;
            col[c] = 0;
            ldiag[r+c] = 0;
            rdiag[(n-1) + (r-c)] = 0;
            board[r][c] = '-';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    vb row(n,false);
    vb col(n,false);
    vb rdiag(2*n-1,false);
    vb ldiag(2*n-1,false);
    nqueen_combi(0, 0, n, row, col, ldiag, rdiag, board);
}