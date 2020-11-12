// #include<iostream>
// #include<unordered_map>
// #include<vector>
// using namespace std;

// bool isword_pattern(string &s, vector<string> &t)
// {
//     unordered_map<char, string> mapst;
//     unordered_map<string, bool> ismapped;
    
//     for(int i = 0; i < s.size(); i++)
//     {
//         // cout<<s[i]<<" "<<t[i]<<endl;
//         if(mapst.find(s[i]) != mapst.end() && mapst[s[i]] != t[i])
//             return false;
//         if(mapst.find(s[i]) == mapst.end() && ismapped[t[i]])
//             return false;
//         mapst[s[i]] = t[i];
//         ismapped[t[i]] = true;
//     }
//     return true;
// }

// int main()
// {
//     string s;
//     cin>>s;
//     vector<string> t(s.size());
//     for(int i = 0; i < s.size(); i++)
//         cin>>t[i];
    
//     cout<<(boolalpha)<<isword_pattern(s, t);
    
//     return 0;
// }


#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    string s, S, T; 
    
    cin>>s;
    cin.ignore();
    getline(cin, S); 
  
    stringstream X(S); 
  
    cout<<s<<endl;
    while (getline(X, T, ' ')) { 
        cout << T << endl; 
    } 
  
    return 0; 
} 