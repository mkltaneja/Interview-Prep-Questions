#include<iostream>
#include<vector>
using namespace std;

vector<string> graycode(int n)
{
    if(n == 0)
        return {"0"};
    if(n == 1)
        return {"0", "1"};
        
    vector<string> arr = graycode(n - 1);
    vector<string> narr;
    for(int i=0; i<arr.size(); i++)
        narr.push_back("0" + arr[i]);
    for(int i=arr.size()-1; i>=0; i--)
        narr.push_back("1" + arr[i]);
    return narr;
}

int to_dec(string &bin)
{
    int n = bin.size() - 1;
    int i = 1, ans = 0;
    while(n >= 0)
    {
        ans += (i * (bin[n--] - '0'));
        i *= 2;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> binarr = graycode(n);
    int sz = binarr.size();
    vector<int> gcodes(sz, 0);
    for(int i=0; i<sz; i++)
        gcodes[i] = to_dec(binarr[i]);
    // for(int i=0; i<sz; i++)
    //     cout<<binarr[i]<<" ";
    
        
    cout<<"[";
    for(int i=0; i<sz-1; i++)
        cout<<gcodes[i]<<", ";
    cout<<gcodes[sz-1]<<"]";
    
    return 0;
}