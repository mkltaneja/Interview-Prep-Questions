#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string minans = "";
void min_softdev(int idx, vector<int> &skills, int m, int skill, int reqskill, string ans)
{
    if(idx == m)
    {
        // cout<<ans<<endl;
        if((skill == reqskill) && (minans.size() == 0 || ans.size() < minans.size()))
        {
            minans = ans;
            // cout<<minans<<endl;
        }
        return;
    }
    min_softdev(idx + 1, skills, m, skill, reqskill, ans);
    min_softdev(idx + 1, skills, m, (skill | skills[idx]), reqskill, ans+to_string(idx));
}

int main()
{
    int n, m;
    cin>>n;
    unordered_map<string, int> skillset;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        skillset.insert({s,i});
    }
    cin>>m;
    vector<int> skills(m,0);
    for(int i=0; i<m; i++)
    {
        int ts;
        cin>>ts;
        for(int j=0; j<ts; j++)
        {
            string s;
            cin>>s;
            skills[i] = skills[i] | (1 << skillset[s]);
        }
    }
    min_softdev(0, skills, m, 0, (1 << n) - 1, "");
    cout<<"[";
    for(int i=0; i<minans.size()-1; i++)
        cout<<minans[i]<<", ";
    cout<<minans[minans.size()-1]<<"]";
    
    return 0;
}