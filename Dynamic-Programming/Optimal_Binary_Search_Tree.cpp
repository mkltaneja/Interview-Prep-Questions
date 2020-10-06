
// METHOD 1
// TLE
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int optimalBST(int si, int ei, int level, vector<int> &key, vector<int> &freq)
{
    if(ei < si)
        return 0;
    
    int optimal_ans = INT_MAX;
    for(int cut = si; cut <= ei; cut++)
    {
        int left = optimalBST(si, cut-1, level+1, key, freq);
        int right = optimalBST(cut+1, ei, level+1, key, freq);
        
        int ans = left + level*freq[cut] + right;
        optimal_ans = min(ans, optimal_ans);
    }
    return optimal_ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> key(n);
    vector<int> freq(n);
    for(int i=0; i<n; i++)
        cin>>key[i];
    for(int i=0; i<n; i++)
        cin>>freq[i];
    cout<<optimalBST(0, n-1, 1, key, freq);
}