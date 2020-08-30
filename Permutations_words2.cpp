#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<string> strings;
void permutations(int idx, string &s, vector<char> &boxes, string ans)
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
            permutations(idx+1, s, boxes, ans+s[idx]);
            boxes[i] = NULL;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    vector<char> boxes(s.size());
    permutations(0, s, boxes, "");
}