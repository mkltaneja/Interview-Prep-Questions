#include<iostream>
#include<vector>
using namespace std;

void permutations(int items, int idx, int n, int m, vector<bool> &item, string ans)
{
    if(idx == n)
    {
        if(items == m)
            cout<<ans<<endl;
        return;
    }
    for(int i=0; i<m; i++)
    {
        if(!item[i])
        {
            item[i] = true;
            permutations(items+1, idx+1, n, m, item, ans + to_string(i+1));
            item[i] = false;
        }
    }
    permutations(items, idx+1, n, m, item, ans + "0");
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> item(m,false);
    permutations(0, 0, n, m, item, "");
}