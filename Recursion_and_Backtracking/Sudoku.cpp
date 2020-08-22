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

void solve_sudoku(int idx, vvi &arr, vi &row, vi &col, vvi &sub, vi &calls)
{
    if(idx == calls.size())
    {
        display(arr);
        return;
    }
    
    int i = calls[idx] / 9;
    int j = calls[idx] % 9;
    for(int num=1; num<=9; num++)
    {
        int mask = (1 << num);
        if(!(row[i] & mask) && !(col[j] & mask) && !(sub[i/3][j/3] & mask))
        {
            arr[i][j] = num;
            row[i] ^= mask;
            col[j] ^= mask;
            sub[i/3][j/3] ^= mask;
            solve_sudoku(idx+1, arr, row, col, sub, calls);
            arr[i][j] = 0;
            row[i] ^= mask;
            col[j] ^= mask;
            sub[i/3][j/3] ^= mask;
        }
    }
}

int main()
{
    vvi arr(9,vi (9,0));
    vi row(9,0);
    vi col(9,0);
    vvi sub(3,vi(3,0));
    vi calls;
    // calls.reserve(81);
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 0)
                calls.push_back(i * 9 + j);
            int mask = (1 << arr[i][j]);
            row[i] |= mask;
            col[j] |= mask;
            sub[i/3][j/3] |= mask;
        }
    }
    solve_sudoku(0,arr,row,col,sub,calls);
}