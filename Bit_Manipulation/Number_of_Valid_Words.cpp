
// METHOD 1 (USING VECTOR)
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, m;
    cin>>n;
    vector<int> words(n,0);
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(char c : s)
            words[i] |= (1 << (c - 'a'));
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        string s;
        cin>>s;
        int count = 0;
        int puzzle = 0;
        for(char c : s)
            puzzle |= (1 << (c - 'a'));
        for(int word : words)
        {
            int n = word;
            if(n & (1 << (s[0] - 'a')))
            {
                while(n)
                {
                    int rsb = (n & -n);
                    if((rsb & puzzle) == 0)
                        break;
                    n -= rsb;
                }
                if(n == 0)
                    count++;
            }
        }
        cout<<s<<" -> "<<count<<endl;
    }
    
    return 0;
}

///////////////////////////////////////////////OR/////////////////////////////

// METHOD 2 (USING MAP AND SET)
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
int main()
{
    int n, m;
    cin>>n;
    unordered_map<char,set<int>> letstr;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        int word = 0;
        for(char c : s)
            word |= (1 << (c - 'a'));
        for(char c : s)
            letstr[c].insert(word);
    }
    
    cin>>m;
    for(int i=0; i<m; i++)
    {
        string s;
        cin>>s;
        int count = 0;
        int puzzle = 0;
        for(char c : s)
            puzzle |= (1 << (c - 'a'));
        
        for(int word : letstr[s[0]])
            if((word & puzzle) == word)
                count++;
        
        cout<<s<<" -> "<<count<<endl;
    }
    
    return 0;
}