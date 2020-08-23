#include<iostream>
#include<vector>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vb vector<bool>
using namespace std;

void display(vvc &board)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            cout<<board[i][j];
        cout<<endl;
    }
}

bool isSafeToPlace_horizontal(int i, int j, vvc &board, string &word)
{
    if(j-1 >= 0 && board[i][j-1] != '+')
        return false;
    if(j+word.size() < board[0].size() && board[i][j+word.size()] != '+')
        return false;
    
    for(int jj=0; jj<word.size(); jj++)
    {
        if(j+jj >= board[0].size())
            return false;
        if(board[i][j+jj] == '-' || board[i][j+jj] == word[jj])
            continue;
        else
            return false;
    }
    return true;
}

vb place_horizontal(int i, int j, vvc &board, string &word)
{
    vb placed(word.size(), false);
    for(int jj=0; jj<word.size(); jj++)
    {
        if(board[i][j+jj] == word[jj])
            continue;
        board[i][j+jj] = word[jj];
        placed[jj] = true;
    }
    return placed;
}

void Unplace_horizontal(int i, int j, vvc &board, string &word, vb &placed)
{
    for(int jj=0; jj<word.size(); jj++)
    {
        if(placed[jj])
            continue;
        board[i][j+jj] = '-';
    }
}

bool isSafeToPlace_vertical(int i, int j, vvc &board, string &word)
{
    if(i-1 >= 0 && board[i-1][j] != '+')
        return false;
    if(i+word.size() < board.size() && board[i+word.size()][j] != '+')
        return false;
    
    for(int ii=0; ii<word.size(); ii++)
    {
        if(i+ii >= board.size())
            return false;
        if(board[i+ii][j] == '-' || board[i+ii][j] == word[ii])
            continue;
        else
            return false;
    }
    return true;
}

vb place_vertical(int i, int j, vvc &board, string &word)
{
    vb placed(word.size(), false);
    for(int ii=0; ii<word.size(); ii++)
    {
        if(board[i+ii][j] == word[ii])
            continue;
        board[i+ii][j] = word[ii];
        placed[ii] = true;
    }
    return placed;
}

void Unplace_vertical(int i, int j, vvc &board, string &word, vb &placed)
{
    for(int ii=0; ii<word.size(); ii++)
    {
        if(placed[ii])
            continue;
        board[i+ii][j] = '-';
    }
}

void solve_crossword(vvc &board, vs &words, int idx)
{
    if(idx == words.size())
    {
        display(board);
        return;
    }
    string word = words[idx];
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(board[i][j] == '-' || board[i][j] == word[0])
            {
                if(isSafeToPlace_horizontal(i, j, board, word))
                {
                    vb placed = place_horizontal(i, j, board, word);
                    solve_crossword(board, words, idx+1);
                    Unplace_horizontal(i, j, board, word, placed);
                }
                if(isSafeToPlace_vertical(i, j, board, word))
                {
                    vb placed = place_vertical(i, j, board, word);
                    solve_crossword(board, words, idx+1);
                    Unplace_vertical(i, j, board, word, placed);
                }
           }
        }
    }
}

int main()
{
    vvc board(10,vc(10));
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cin>>board[i][j];
    int n;
    cin>>n;
    vs words(n,"");
    for(int i=0; i<n; i++)
        cin>>words[i];
    
    solve_crossword(board,words,0);
}