
// METHOD 1

#include<iostream>
#include<vector>
using namespace std;

void markpositions(int r, int c, int n, vector<vector<int>> &notsafe)
{
    notsafe[r][c]++;
    if(r - 2 >= 0 && c - 1 >= 0)
        notsafe[r-2][c-1]++;
    if(r - 2 >= 0 && c + 1 < n)
        notsafe[r-2][c+1]++;
    if(r + 2 < n && c - 1 >= 0)
        notsafe[r+2][c-1]++;
    if(r + 2 < n && c + 1 < n)
        notsafe[r+2][c+1]++;
    if(c - 2 >= 0 && r - 1 >= 0)
        notsafe[r-1][c-2]++;
    if(c - 2 >= 0 && r + 1 < n)
        notsafe[r+1][c-2]++;
    if(c + 2 < n && r - 1 >= 0)
        notsafe[r-1][c+2]++;
    if(c + 2 < n && r + 1 < n)
        notsafe[r+1][c+2]++;
}

void unmarkpositions(int r, int c, int n, vector<vector<int>> &notsafe)
{
    notsafe[r][c]--;
    if(r - 2 >= 0 && c - 1 >= 0)
        notsafe[r-2][c-1]--;
    if(r - 2 >= 0 && c + 1 < n)
        notsafe[r-2][c+1]--;
    if(r + 2 < n && c - 1 >= 0)
        notsafe[r+2][c-1]--;
    if(r + 2 < n && c + 1 < n)
        notsafe[r+2][c+1]--;
    if(c - 2 >= 0 && r - 1 >= 0)
        notsafe[r-1][c-2]--;
    if(c - 2 >= 0 && r + 1 < n)
        notsafe[r+1][c-2]--;
    if(c + 2 < n && r - 1 >= 0)
        notsafe[r-1][c+2]--;
    if(c + 2 < n && r + 1 < n)
        notsafe[r+1][c+2]--;
}

void nknights_combi(int idx, int kpsf, int n, vector<vector<int>> &notsafe, vector<vector<char>> &board)
{
    if(kpsf == n)
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
        if(!notsafe[r][c])
        {
            markpositions(r, c, n, notsafe);
            board[r][c] = 'k';
            nknights_combi(i+1, kpsf+1, n, notsafe, board);
            board[r][c] = '-';
            unmarkpositions(r, c, n, notsafe);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    vector<vector<int>> notsafe(n,vector<int>(n,0));
    nknights_combi(0, 0, n, notsafe, board);
}

///////////////////////////////////////////////////OR///////////////////////////////////////

// METHOD 2 (shorter and optimized --> checking previous positions if there is a knight placed)
#include<iostream>
#include<vector>
using namespace std;

bool isSafetoPlace(int r, int c, vector<vector<bool>> &board)
{
    if(r - 2 >= 0 && c - 1 >= 0 && board[r-2][c-1])
        return false;
    if(r - 2 >= 0 && c + 1 >= 0 && board[r-2][c+1])
        return false;
    if(r - 1 >= 0 && c - 2 >= 0 && board[r-1][c-2])
        return false;
    if(r - 1 >= 0 && c + 2 >= 0 && board[r-1][c+2])
        return false;
    return true;
}

void nknights_combi(int idx, int kpsf, int n, vector<vector<bool>> &board)
{
    if(kpsf == n)
    {
        for(vector<bool> v : board)
        {
            for(bool c : v)
                c == 1 ? cout<<"k\t" : cout<<"-\t";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=idx; i<n*n; i++)
    {
        int r = i / n;
        int c = i % n;
        if(!board[r][c] && isSafetoPlace(r,c,board))
        {
            board[r][c] = true;
            nknights_combi(i+1, kpsf+1, n, board);
            board[r][c] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    nknights_combi(0, 0, n, board);
}