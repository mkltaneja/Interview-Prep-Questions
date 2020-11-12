#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largest_equal012_subarray(int n, vector<int> &arr)
{
    unordered_map<string,int> diff012;
    int zeros = 0, ones = 0, twos = 0;
    int diff10 = ones - zeros, diff21 = twos - ones;
    int maxlen = 0;
    
    string key = to_string(diff10) + "#" + to_string(diff21);
    diff012.insert({key, -1});
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            zeros++;
        else if(arr[i] == 1)
            ones++;
        else
            twos++;
        
        diff10 = ones - zeros, diff21 = twos - ones;
        key = to_string(diff10) + "#" + to_string(diff21);
        
        if(diff012.find(key) == diff012.end())
            diff012.insert({key, i});
        else
            maxlen = max(maxlen, i - diff012[key]);
    }
    
    return maxlen;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
        
    cout<<largest_equal012_subarray(n, arr);
    
    return 0;
}