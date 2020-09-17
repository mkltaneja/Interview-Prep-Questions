
// APPROACH 1 (using set) --> O(2^n * logn)
// TLE
#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set <string> st;
void countsubseq(int idx, string &s, string ans)
{
    if(idx == s.size())
    {
        if(ans != "" && st.find(ans) == st.end())
            st.insert(ans);
        return;
    }
    countsubseq(idx + 1, s, ans + s[idx]);
    countsubseq(idx + 1, s, ans);
}

int main()
{
    string s;
    cin>>s;
    countsubseq(0, s, "");
    cout<<st.size();
}

/////////////////////////////////////////////OR/////////////////////////////////////

// APPROACH 2 (DP)
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> lastpos(26,-1);
    vector<long> dp(s.size()+1, 0);
    dp[0] = 1;
    for(int i=1; i<=s.size(); i++)
    {
        dp[i] = 2*dp[i-1];
        if(lastpos[s[i-1] - 'a'] != -1)
            dp[i] -= dp[lastpos[s[i-1] - 'a']];
        lastpos[s[i-1] - 'a'] = i-1;
    }
    cout<<dp[s.size()]-1;
}