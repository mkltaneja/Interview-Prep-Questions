#include<iostream>
#include<stack>
#include<unordered_set>
using namespace std;

int minremoval(string &s)
{
    stack<char> st;
    for(char c : s)
    {
        if(c == '(')
            st.push(c);
        else if(c == ')')
        {
            if(st.empty() || st.top() == ')')
                st.push(c);
            else if(st.top() == '(')
                st.pop();
        }
    }
    return st.size();
}

void valid_parenthesis(string s, int mra, unordered_set<string> &pars)
{
    if(mra == 0)
    {
        int mrnow = minremoval(s);
        if(mrnow == 0 && pars.find(s) == pars.end())
        {
            cout<<s<<endl;
            pars.insert(s);
        }
        return;
    }
    
    for(int i=0; i<s.size(); i++)
        valid_parenthesis(s.substr(0,i)+s.substr(i+1), mra-1, pars);
}

int main()
{
    string s;
    cin>>s;
    int st = 0;
    while(st < s.length() && s[st] == ')') st++;
    int end = s.length() - 1;
    while(end >= st && s[end] == '(') end--;
    s = s.substr(st, end-st+1);
    int invalids = minremoval(s);
    unordered_set<string> pars;
    valid_parenthesis(s,invalids,pars);
}