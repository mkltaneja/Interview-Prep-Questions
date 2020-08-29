#include<iostream>
#include<stack>
#include<unordered_set>
#include<time.h>
#include<iomanip>
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
    
    int invalids = minremoval(s);
    // cout<<invalids<<endl;
    unordered_set<string> pars;
    clock_t start = clock();
    valid_parenthesis(s,invalids,pars);
    clock_t end = clock();
    double duration = 1.0*(end - start) / CLOCKS_PER_SEC;
    cout<<fixed<<showpoint<<setprecision(5);
    cout<<duration<<endl;
}