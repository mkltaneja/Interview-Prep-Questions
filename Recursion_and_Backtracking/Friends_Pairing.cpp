#include<iostream>
#include<vector>
using namespace std;

int base = 1;
void friends_pairing(int idx, int n, vector<bool> &used, string ans)
{
    if(idx == n+1)
    {
        cout<<base++<<"."<<ans<<endl;
        return;
    }
    if(used[idx])
        friends_pairing(idx+1, n, used, ans);
    else
    {
        used[idx] = true;
        friends_pairing(idx+1, n, used, ans+"("+to_string(idx)+") ");
        for(int i=idx+1; i<=n; i++)
        {
            if(!used[i])
            {
                used[i] = true;
                friends_pairing(idx+1, n, used, ans+"("+to_string(idx)+","+to_string(i)+") ");
                used[i] = false;
            }
        }
        used[idx] = false;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<bool> used(n+1,false);
    friends_pairing(1,n,used,"");
}