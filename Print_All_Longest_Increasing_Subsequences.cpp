// #include<iostream>
// #include<vector>
// #define f first
// #define s second
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++)
//         cin>>arr[i];
    
//     vector<pair<int,vector<string>>> dp(n);
//     for(int i=0; i<n; i++)
//     {
//         dp[i].f = 1;
//         dp[i].s.push_back(to_string(arr[i]));
//     }
    
//     for(int i=0; i<n; i++)
//     {
//         for(int j=i-1; j>=0; j--)
//         {
//             if(arr[j] < arr[i])
//             {
//                 if(dp[j].f + 1 > dp[i].f)
//                 {
//                     dp[i].s.clear();
//                     dp[i].f = dp[j].f + 1;
//                     for(string str : dp[j].s)
//                     {
//                         str += " -> " + to_string(arr[i]);
//                         dp[i].s.push_back(str);
//                     }
//                 }
//                 else if(dp[j].f + 1 == dp[i].f)
//                 {
//                     for(string str : dp[j].s)
//                     {
//                         str += " -> " + to_string(arr[i]);
//                         dp[i].s.push_back(str);
//                     }
//                 }
//             }
//         }
//     }
    
//     vector<string> ans;
//     int maxi = 0;
//     for(auto itr : dp)
//     {
//         if(itr.f > maxi)
//         {
//             maxi = itr.f;
//             ans.clear();
//             for(string str : itr.s)
//                 ans.push_back(str);
//         }
//         else if(itr.f == maxi)
//         {
//             for(string str : itr.s)
//                 ans.push_back(str);
//         }
//     }
    
//     cout<<maxi<<endl;
//     for(string str : ans)
//         cout<<str<<endl;
    
//     return 0;   
// }

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
    // for(int i : dp)
    //     cout<<i<<" ";
    queue<Pair> que;
    que.push(Pair(maxidx, maxlen, arr[maxidx], to_string(arr[maxidx])));
    while(!que.empty())
    {
        Pair rm = que.front();
        que.pop();
        cout<<rm.e<<endl;
        if(rm.l == 1)
            cout<<rm.lis<<endl;
        
        for(int i = rm.i; i >= 0; i--)
            if(dp[i] == rm.l - 1 && arr[i] <= rm.e)
                que.push(Pair(i, dp[i], arr[i], to_string(arr[i]) + " -> " + rm.lis));
    }
    
    return 0;   
}