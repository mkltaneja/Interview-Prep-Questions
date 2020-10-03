#include<iostream>
#include<vector>
using namespace std;

int bool_parenthesization(int n, string &s, string &t, vector<vector<int>> &trues, vector<vector<int>> &falses)
{
    for(int gap = 0; gap < n; gap++)
    {
        for(int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if(gap == 0)
            {
                trues[si][ei] = (s[si] == 'T') ? 1 : 0;
                falses[si][ei] = (s[si] == 'F') ? 1 : 0;
                continue;
            }
            for(int cut = si; cut < ei; cut++)
            {
                int lefttrues = trues[si][cut];
                int righttrues = trues[cut+1][ei];
                int leftfalses = falses[si][cut];
                int rightfalses = falses[cut+1][ei];
                
                int TT = lefttrues * righttrues;
                int TF = lefttrues * rightfalses;
                int FT = leftfalses * righttrues;
                int FF = leftfalses * rightfalses;
                
                if(t[cut] == '|')
                {
                    trues[si][ei] += TT + TF + FT;
                    falses[si][ei] += FF;
                }
                else if(t[cut] == '&')
                {
                    trues[si][ei] += TT;
                    falses[si][ei] += FF + TF + FT;
                }
                else if(t[cut] == '^')
                {
                    trues[si][ei] += TF + FT;
                    falses[si][ei] += TT + FF;
                }
            }
        }
    }
    return trues[0][n-1];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    
    vector<vector<int>> trues(s1.size(), vector<int>(s1.size(),0));
    vector<vector<int>> falses(s1.size(), vector<int>(s1.size(),0));
    
    cout<<bool_parenthesization(s1.size(), s1, s2, trues, falses);
    
    return 0;
}