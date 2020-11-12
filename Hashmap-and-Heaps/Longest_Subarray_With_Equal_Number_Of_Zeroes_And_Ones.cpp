#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largest_equal01_subarray(int n, vector<int> &arr)
{
    unordered_map<int,int> diff01;
    int diff = 0, maxlen = 0;
    diff01.insert({0,-1});
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            diff--;
        else
            diff++;
        if(diff01.find(diff) == diff01.end())
            diff01.insert({diff, i});
        else
            maxlen = max(maxlen, i-diff01[diff]);
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
    
    cout<<largest_equal01_subarray(n, arr);
    
    return 0;
}
