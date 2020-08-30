
// METHOD 1 (using hashmap to pervent string duplicacy)=========================

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<string> strings;
void permutations(int idx, string &s, vector<char> &boxes)
{
    if(idx == s.size())
    {
        string temp = "";
        for(char c : boxes)
            temp += c;
        
        if(strings.find(temp) == strings.end())
        {
            strings.insert(temp);
            cout<<temp<<endl;
        }
        return;
    }
    for(int i=0; i<boxes.size(); i++)
    {
        if(!boxes[i])
        {
            boxes[i] = s[idx];
            permutations(idx+1, s, boxes);
            boxes[i] = NULL;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<char> boxes(s.size());
    permutations(0, s, boxes);
}

////////////////////////////////////////////OR//////////////////////////////////////////

// METHOD 2 (using last occurance of the same character in the string to prevent duplicacy)

#include<iostream>
#include<vector>
using namespace std;

void permutations(int idx, string &s, vector<char> &boxes, vector<int> &lastocc)
{
    if(idx == s.size())
    {
        for(char c : boxes)
            cout<<c;
        cout<<endl;
        return;
    }
    int lo = lastocc[s[idx] - 'a'];
    for(int i=lo+1; i<boxes.size(); i++)
    {
        if(!boxes[i])
        {
            lastocc[s[idx] - 'a'] = i;
            boxes[i] = s[idx];
            permutations(idx+1, s, boxes, lastocc);
            lastocc[s[idx] - 'a'] = lo;
            boxes[i] = NULL;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<char> boxes(s.size());
    vector<int> lastocc(26,-1);
    permutations(0, s, boxes, lastocc);
}