#include<iostream>
#include<vector>
using namespace std;

int countPS(int n, string &s, vector<vector<bool>> &ispal)
{
    int countpal = 0;
    for(int gap = 0; gap < n; gap++)
    {
        for(int i=0, j=gap; j < n; i++, j++)
        {
            if(gap == 0)
                ispal[i][j] = true;
            else if(gap == 1)
            {
                if(s[i] == s[j])
                    ispal[i][j] = true;
                else
                    ispal[i][j] = false;
            }
            else
            {
                if((s[i] == s[j]) && ispal[i+1][j-1] == true)
                    ispal[i][j] = true;
                else
                    ispal[i][j] = false;
            }
            if(ispal[i][j])
                countpal++;
        }
    }
    return countpal;
}

int main()
{
    string s;
    cin>>s;
    vector<vector<bool>> ispalindrome(s.size(), vector<bool>(s.size(),false));
    cout<<countPS(s.size(), s, ispalindrome);
}