#include<iostream>
#include<vector>
using namespace std;

void permutations(string &s, vector<bool> &item, string ans)
{
    if(ans.size() == s.size())
    {
        cout<<ans<<endl;
        return;
    }
    int visc = 0;
    for(int i=0; i<s.size(); i++)
    {
        int mask = (1 << (s[i] - 'a'));
        if(!(visc & mask) && !(item[i]))
        {
            item[i] = true;
            visc ^= mask;
            permutations(s, item, ans+s[i]);
            item[i] = false;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<bool> item(s.size(), false);
    permutations(s, item, "");
}