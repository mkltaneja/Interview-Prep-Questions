#include<iostream>
#include<vector>
using namespace std;

void queen_combi(int qpsf, int n, vector<bool> &row, vector<bool> &col, vector<bool> &ldiag, vector<bool> &rdiag, vector<vector<char>> &board)
{
    if(qpsf == n+1)
    {
        for(vector<char> v : board)
        {
            for(char c : v)
                c == '-' ? cout<<c<<"\t" : cout<<"q"<<c<<"\t";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i=0; i<n*n; i++)
    {
        int r = i / n;
        int c = i % n;
        if(!row[r] && !col[c] && !ldiag[r+c] && !rdiag[(r-c)+(n-1)])
        {
            row[r] = true;
            col[c] = true;
            ldiag[r+c] = true;
            rdiag[(r-c)+(n-1)] = true;
            board[r][c] = (char)(qpsf + '0');
            queen_combi(qpsf+1, n, row, col, ldiag, rdiag, board);
            board[r][c] = '-';
            row[r] = false;
            col[c] = false;
            ldiag[r+c] = false;
            rdiag[(r-c)+(n-1)] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n, vector<char>(n,'-'));
    vector<bool> row(n,false);
    vector<bool> col(n,false);
    vector<bool> ldiag(2*n-1,false);
    vector<bool> rdiag(2*n-1,false);
    
    queen_combi(1, n, row, col, ldiag, rdiag, board);
}