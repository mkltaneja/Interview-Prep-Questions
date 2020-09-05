#include<iostream>
#include<vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

void display(vvi &arr)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

void Sudoku(int idx, vi &r, vi &c, vvi &sub, vvi &arr)
{
    // cout<<idx<<endl;
    if(idx == 81)
    {
        display(arr);
        cout<<endl;
        return;
    }
    int i = idx / 9;
    int j = idx % 9;
    
    if(arr[i][j] > 0)
        Sudoku(idx + 1, r, c, sub, arr);
    else
    {
        for(int num=1; num<=9; num++)
        {
            int mask = (1 << num);
            if(!(r[i] & mask) && !(c[j] & mask) && !(sub[i/3][j/3] & mask))
            {
                r[i] ^= mask;
                c[j] ^= mask;
                sub[i/3][j/3] ^= mask;
                arr[i][j] = num;
                Sudoku(idx + 1, r, c, sub, arr);
                r[i] ^= mask;
                c[j] ^= mask;
                sub[i/3][j/3] ^= mask;
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    vvi board(9,vi(9,0));
    vi r(9,0), c(9,0);
    vvi sub(3,vi(3,0));
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>board[i][j];
            r[i] |= (1 << board[i][j]);
            c[j] |= (1 << board[i][j]);
            sub[i/3][j/3] |= (1 << board[i][j]);
        }
    }
    Sudoku(0, r, c, sub, board);
}