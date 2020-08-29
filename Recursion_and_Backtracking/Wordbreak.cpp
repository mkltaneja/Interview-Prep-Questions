
// Method 1 (using hashset)

// #include<iostream>
// #include<unordered_set>
// using namespace std;

// void wordbreak(string que, unordered_set<string> &dict, string ans)
// {
//     if(que.size() == 0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     string s = "";
//     for(int i=0; i<que.size(); i++)
//     {
//         s += que[i];
//         if(dict.find(s) != dict.end())
//             wordbreak(que.substr(s.size()), dict, ans+s+" ");
//     }
// }

// int main()
// {
//     int n;
//     cin>>n;
//     unordered_set<string> dict;
//     for(int i=0; i<n; i++)
//     {
//         string s;
//         cin>>s;
//         dict.insert(s);
//     }
//     string sent;
//     cin>>sent;
//     wordbreak(sent, dict, "");
// }

////////////////////////////////////////////////////OR///////////////////////////////////////

// Method 2(using trie)
// FASTER
#include<iostream>
#include<vector>
using namespace std;

class trie
{
    public:
    vector<trie*> t;
    bool wordEnd;
    trie()
    {
        t.assign(26,nullptr);
        wordEnd = false;
    }
};
trie* root = new trie();

void insert(vector<string> &arr)
{
    for(string s : arr)
    {
        trie* curr = root;
        for(char c : s)
        {
            if(!curr->t[c - 'a'])
                curr->t[c - 'a'] = new trie();
            curr = curr->t[c - 'a'];
        }
        curr->wordEnd = true;
    }
}

void wordbreak(string que, string ans)
{
    if(que.size() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    string s = "";
    trie* curr = root;
    for(int i=0; i<que.size(); i++)
    {
        s += que[i];
        if(curr->t[que[i] - 'a'])
        {
            curr = curr->t[que[i] - 'a'];
            if(curr->wordEnd)
                wordbreak(que.substr(s.size()), ans+s+" ");
        }
        else 
            break;
    }
}

int main()
{
    string s = "Mukul";
    for(int i=0; i<s.size(); i++)
        cout<<s.substr(0,i)<<" "<<s.substr(i+1)<<endl;
    // int n;
    // cin>>n;
    // vector<string> dict(n);
    // for(int i=0; i<n; i++)
    // {
    //     cin>>dict[i];
    // }
    // string sent;
    // cin>>sent;

    // insert(dict);
    // wordbreak(sent, "");
}