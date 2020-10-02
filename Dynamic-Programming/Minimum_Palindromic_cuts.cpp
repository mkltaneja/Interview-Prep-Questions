#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    
    vector<vector<bool>> ispal(n, vector<bool>(n, 0));
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {
            if(gap == 0)
                ispal[i][j] = true;
            else if(gap == 1)
                ispal[i][j] = (s[i] == s[j]);
            else
                ispal[i][j] = (s[i] == s[j] && ispal[i+1][j-1]);
        }
    }
    // for(auto v : ispal)
    // {
    //     for(int i : v)
    //         cout<<i<<" \t";
    //     cout<<endl;
    // }
    // cout<<endl;
    
    vector<vector<int>> mincuts(n, vector<int>(n, -1));
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {
            // cout<<i<<" "<<j<<" :\n";
            if(gap == 0)
                mincuts[i][j] = 0;
            if(gap == 1)
            {
                if(s[i] == s[j])
                    mincuts[i][j] = 0;
                else
                    mincuts[i][j] = 1;
            }
            else
            {
                if(ispal[i][j])
                    mincuts[i][j] = 0;
                else
                {
                    int minans = INT_MAX;
                    for(int x = i; x < j; x++)
                    {
                        // cout<<i<<" "<<x<<", "<<x+1<<" "<<j<<endl;
                        minans = min(minans, mincuts[i][x] + mincuts[x+1][j]);
                    }
                    mincuts[i][j] = minans + 1;
                }
            }
        }
    }
    
    // for(auto v : mincuts)
    // {
    //     for(int i : v)
    //         cout<<i<<" \t";
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<mincuts[0][n-1];
    
    return 0;
}

/////////////////////////////////////////////////////////OR/////////////////////////////////////////////

// METHOD 2 (Selecting Palindromic Prefixes)
// O(n^2)
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<bool>> ispal(n,vector<bool>(n,0));
    
    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; i++, j++)
        {
            if(gap == 0)
                ispal[i][j] = true;
            else if(gap == 1)
                ispal[i][j] = (s[i] == s[j]);
            else
                ispal[i][j] = (s[i] == s[j] && ispal[i+1][j-1]);
        }
    }
    
    // for(auto v : ispal)
    // {
    //     for(int i : v)
    //         cout<<i<<" ";
    //     cout<<endl;
    // }
    
    vector<int> mincuts(n,0);
    
    for(int end = 0; end < n; end++)
    {
        if(ispal[0][end])
            mincuts[end] = 0;
        else
        {
            int cuts = INT_MAX;
            for(int st = end; st >= 1; st--)
            {
                if(ispal[st][end])
                    cuts = min(cuts, mincuts[st-1]);
                mincuts[end] = cuts + 1;
            }
        }
    }
    
    // for(auto v : mincuts)
    //     cout<<v<<" ";
    // cout<<endl;
    cout<<mincuts[n-1];
    
    return 0;
}