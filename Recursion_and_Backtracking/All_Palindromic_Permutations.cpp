#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindrome(string &s)
{
    for(int i=0; i<s.size()/2; i++)
        if(s[i] != s[s.size()-i-1])
            return false;
    return true;
}

bool pal = false;
void permutations(string &que, vector<bool> &iu, string ans)
{
    if(ans.size() == que.size())
    {
        if(isPalindrome(ans))
        {
            pal = true;
            cout<<ans<<endl;
        }
        return;
    }
    // cout<<ans<<endl;
    vector<bool> cu(26,false);
    for(int i=0; i<que.size(); i++)
    {
        if(!cu[que[i] - 'a'] && !iu[i])
        {
            iu[i] = true;
            cu[que[i] - 'a'] = true;
            permutations(que, iu, ans + que[i]);
            iu[i] = false;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    // sort(s.begin(),s.end(),[](char &a, char &b){
    //     return a < b;
    // });
    vector<bool> iused(s.size(),false);
    permutations(s,iused,"");
    if(!pal)
        cout<<-1<<endl;
}

///////////////////////////////////////////// OR ///////////////////////////////////////////

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void permutations(int idx, int len, vector<pair<char,int>> &que, char oc, string ans)
{
    if(idx == len)
    {
        string res = ans;
        if(oc)
            res += oc;
        for(int i=0; i<ans.size(); i++)
            res += ans[ans.size()-i-1];
        cout<<res<<endl;
        
        return;
    }
    
    for(int i=0 ; i<len; i++)
    {
        char ch = que[i].first;
        int f = que[i].second;
        if(f > 0)
        {
            que[i].second = f-1;
            permutations(idx+1, len, que, oc, ans+ch);
            que[i].second = f;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<int> count(26,0);
    for(char c : s)
        count[c-'a']++;
    
    int odds = 0, len = 0;
    char oddc;
    for(int i=0; i<26; i++)
    {
        char ch = (char)(i+'a');
        int f = count[i];
        // cout<<ch<<" "<<f<<endl;
        if(f & 1)
        {
            oddc = ch;
            odds++;
        }
        count[i] = f/2;
        len += f/2;
    }
    if(odds > 1)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<pair<char,int>> que(len);
    int idx = 0;
    for(char c : s)
        if(count[c - 'a'] > 0)
            que[idx++] = {c,count[c - 'a']}, count[c - 'a'] = 0;
    permutations(0,len,que,oddc,"");
}