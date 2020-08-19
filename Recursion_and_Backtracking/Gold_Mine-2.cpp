#include<iostream>
#include<vector>
using namespace std;

int mgold_gcc(int r, int c, int n, int m, vector<vector<int>> &grid)
{
    if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
        return 0;
    int gold = grid[r][c];
    grid[r][c] = 0;
    
    gold += mgold_gcc(r+1, c, n, m, grid);
    gold += mgold_gcc(r, c+1, n, m, grid);
    gold += mgold_gcc(r-1, c, n, m, grid);
    gold += mgold_gcc(r, c-1, n, m, grid);
    return gold;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    
    int maxgold = 0;
    // vector<int> tempgrid(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] != 0)
                maxgold = max(maxgold, mgold_gcc(i,j,n,m,grid));
    cout<<maxgold<<endl;
}