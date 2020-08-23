// METHOD 1 (USING MAP)
// TLE

#include<iostream>
#include<map>
#include<vector>
using namespace std;

void display(map<char,int> &m)
{
    for(auto i : m)
        cout<<i.first<<"-"<<i.second<<" ";
    cout<<endl;
}

int getnum(string &s, map<char,int> &m)
{
    int num = 0;
    for(char c : s)
    {
        num *= 10;
        num += m[c];
    }
    return num;
}

string s1, s2, s3;

void cryptarithmetic(int idx, map<char,int> &m, string &unique, vector<bool> &used)
{
    if(idx == unique.size())
    {
        int num1 = getnum(s1, m);
        int num2 = getnum(s2, m);
        int num3 = getnum(s3, m);
        if(num1 + num2 == num3)
            display(m);
        return;
    }
    
    for(int i=0; i<=9; i++)
    {
        if(!used[i])
        {
            used[i] = true;
            m[unique[idx]] = i;
            cryptarithmetic(idx+1, m, unique, used);
            used[i] = false;
            m[unique[idx]] = -1;
        }
    }
}

int main()
{
    cin>>s1>>s2>>s3;
    map<char,int> m;
    string unique = "";
    
    for(char c : s1)
    {
        if(m.find(c) == m.end())
        {
            m.insert({c,-1});
            unique += c;
        }
    }
    for(char c : s2)
    {
        if(m.find(c) == m.end())
        {
            m.insert({c,-1});
            unique += c;
        }
    }
    for(char c : s3)
    {
        if(m.find(c) == m.end())
        {
            m.insert({c,-1});
            unique += c;
        }
    }
    vector<bool> used(10,false);
    
    cryptarithmetic(0,m,unique,used);
}
