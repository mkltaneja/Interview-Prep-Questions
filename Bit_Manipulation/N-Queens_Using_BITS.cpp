#include<iostream>
using namespace std;

void nqueen(int r, int c, int ld, int rd, int n, string ans)
{
    if(r == n)
    {
        cout<<ans<<"."<<endl;
        return;
    }
    for(int j=0; j<n; j++)
    {
        int cm = (1 << j);
        int ldm = (1 << (r+j));
        int rdm = (1 << ((r-j)+(n-1)));
        if(!(c & cm) && !(ld & ldm) && !(rd & rdm))
            nqueen(r+1, (c ^ cm), (ld ^ ldm), (rd ^ rdm), n, ans + to_string(r)+"-"+to_string(j)+", ");
    }
}

int main()
{
    int n;
    cin>>n;
    int c = 0, ld = 0, rd = 0;
    nqueen(0, c, ld, rd, n, "");
}