#include<iostream>
#include<vector>
#define vb vector<bool>
using namespace std;

void n_queen(int idx, int n, vb &col, vb &rdiag, vb &ldiag, string comb)
{
    if(idx == n)
    {
        cout<<comb<<"."<<endl;
        return;
    }
    
    for(int j=0; j<n; j++)
    {
        if(!col[j] && !ldiag[idx+j] && !rdiag[(n-1)-(idx-j)])
        {
            col[j] = 1;
            ldiag[idx+j] = 1;
            rdiag[(n-1) - (idx-j)] = 1;
            n_queen(idx+1, n, col, rdiag, ldiag, comb+to_string(idx)+"-"+to_string(j)+", ");
            col[j] = 0;
            ldiag[idx+j] = 0;
            rdiag[(n-1) - (idx-j)] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vb col(n,false);
    vb rdiag(2*n-1,false);
    vb ldiag(2*n-1,false);
    
    n_queen(0, n, col, rdiag, ldiag, "");
    
    return 0;
}