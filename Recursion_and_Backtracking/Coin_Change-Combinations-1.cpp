
// APPROACH 1
// (AMOUNT WISE CALLING)

#include<iostream>
#include<vector>
using namespace std;

void coinchange_combi(int idx, int n, vector<int> &coins, int amt, string ans)
{
    if(amt == 0)
    {
        cout<<ans<<"."<<endl;
        return;
    }
    for(int i=idx; i<n; i++)
        if(amt - coins[i] >= 0)
            coinchange_combi(i+1, n, coins, amt-coins[i], ans+to_string(coins[i])+"-");
}

int main()
{
    int n, amt;
    cin>>n;
    vector<int> coins(n,0);
    for(int i=0; i<n; i++)
        cin>>coins[i];
    cin>>amt;
    coinchange_combi(0, n, coins, amt, "");
}

//////////////////////////////////////////////////OR///////////////////////////////////

// APPROACH 2
// (COIN WISE CALLING)

#include<iostream>
#include<vector>
using namespace std;

void coinchange_combi(int idx, int n, vector<int> &coins, int amt, string ans)
{
    if(idx == n)
    {
        if(amt == 0)
        {
            cout<<ans<<"."<<endl;
        }
        return;
    }
    coinchange_combi(idx+1, n, coins, amt - coins[idx], ans + to_string(coins[idx]) + "-");
    coinchange_combi(idx+1, n, coins, amt, ans);
}

int main()
{
    int n, amt;
    cin>>n;
    vector<int> coins(n,0);
    for(int i=0; i<n; i++)
        cin>>coins[i];
    cin>>amt;
    coinchange_combi(0, n, coins, amt, "");
}