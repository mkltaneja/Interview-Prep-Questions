
// METHOD 1 (using 2D Board)

#include<iostream>
#include<vector>
using namespace std;

void queen_permu(int r, int c, int qpsf, int n, vector<bool> &placed, vector<vector<int>> &board)
{
    if(r == n)
    {
        if(qpsf == n)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    board[i][j] == 0 ? cout<<"-\t" : cout<<"q"<<board[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
        return;
    }
    
    int nr = 0, nc = 0;
    if(c == n-1)
    {
        nr = r + 1;
        nc = 0;
    }
    else
    {
        nr = r;
        nc = c + 1;
    }
    if(board[r][c] == 0)
    {
        for(int q=0; q<placed.size(); q++)
        {
            if(!placed[q])
            {
                placed[q] = true;
                board[r][c] = q+1;
                queen_permu(nr, nc, qpsf+1, n, placed, board);
                board[r][c] = 0;
                placed[q] = false;
            }
        }
    }
    queen_permu(nr, nc, qpsf, n, placed, board);
}

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<bool> placed(n,false);
    queen_permu(0, 0, 0, n, placed, board);
}

/////////////////////////////////////////////OR/////////////////////////////////////////////

// METHOD 2 (using string)

#include<iostream>
#include<vector>
using namespace std;

void queen_permu(int r, int c, int qpsf, int n, vector<bool> &placed, string ans)
{
    if(r == n)
    {
        if(qpsf == n)
            cout<<ans<<endl<<endl;
        return;
    }
    
    int nr = 0, nc = 0;
    char sep = '\0';
    if(c == n-1)
    {
        nr = r + 1;
        nc = 0;
        sep = '\n';
    }
    else
    {
        nr = r;
        nc = c + 1;
        sep = '\t';
    }
    for(int q=0; q<placed.size(); q++)
    {
        if(!placed[q])
        {
            placed[q] = true;
            queen_permu(nr, nc, qpsf+1, n, placed, ans + 'q' + to_string(q+1) + sep);
            placed[q] = false;
        }
    }
    queen_permu(nr, nc, qpsf, n, placed, ans+ '-' +sep);
}

int main()
{
    int n;
    cin>>n;
    
    vector<bool> placed(n,false);
    queen_permu(0, 0, 0, n, placed, "");
}