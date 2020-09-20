#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Pair
{
public:
    int i;
    int l;
    int e;
    string lis;
    Pair(int idx, int len, int ele, string str)
    {
        this->i = idx;
        this->l = len;
        this->e = ele;
        this->lis = str;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vector<int> dp(n,1);
    int maxlen = 0, maxidx = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j] <= arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if(dp[i] > maxlen)
        {
            maxlen = dp[i];
            maxidx = i;
        }
    }
    queue<Pair> que;
    for(int i=0; i<n; i++)
        if(dp[i] == maxlen)
            que.push(Pair(i, maxlen, arr[i], to_string(arr[i]) + ""));
    cout<<maxlen<<endl;
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        
        if(rm.l == 1)
            cout<<rm.lis<<endl;
        
        for(int j = rm.i; j >= 0; j--)
            if(dp[j] == rm.l - 1 && arr[j] <= rm.e)
                que.push(Pair(j, dp[j], arr[j], to_string(arr[j]) + " -> " + rm.lis));
    }
    
    return 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}