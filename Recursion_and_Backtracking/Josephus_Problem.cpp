#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k,count = 0;
    cin>>n>>k;
    int k1 = 1;
    vector<bool> vis(n, false);
    for(int i=0;count<n-1;i=(++i)%n)
    {
        if(vis[i])
            continue;
        if(k1 == k)
        {
            // cout<<i<<" ";
            vis[i] = true;
            k1 = 0;
            count++;
        }
        k1++;
    }
    int lucky;
    for(int i=0; i<n;i++)
        if(!vis[i])
            lucky = i;
    cout<<lucky<<endl;
    return 0;
}

// OR

#include<iostream>
#include<vector>
using namespace std;

int lucky(int n, int k)
{
    if(n == 1)
        return 0;
    int x = lucky(n-1, k);
    int y = (x + k) % n;
    return y;
}

int main()
{
    int n,k,count = 0;
    cin>>n>>k;
    cout<<lucky(n,k)<<endl;
    return 0;
}