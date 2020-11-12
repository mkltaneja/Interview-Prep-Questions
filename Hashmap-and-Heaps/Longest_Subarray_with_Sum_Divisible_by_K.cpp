#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longest_subarray_withsum_divbyK(int n, vector<int> &arr, int k)
{
    unordered_map<int,int> rem;
    rem.insert({0, -1});
    int sum = 0, maxlen = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        int sumrem = sum % k;
        if(sumrem < 0)
            sumrem += k;
        
        if(rem.find(sumrem) == rem.end())
            rem.insert({sumrem, i});
        else
            maxlen = max(maxlen, i-rem[sumrem]);
    }
    return maxlen;
}

int main()
{
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>k;
    
    cout<<longest_subarray_withsum_divbyK(n, arr, k);
    
    return 0;
}