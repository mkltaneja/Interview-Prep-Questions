#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int count_subarrays_withsum_divbyK(int n, vector<int> &arr, int k)
{
    unordered_map<int, int> remcount;
    int sum = 0, count = 0;
    remcount.insert({0,1});
    
    for(int i : arr)
    {
        sum += i;
        int sumrem = sum % k;
        if(sumrem < 0)
            sumrem += k;
        if(remcount.find(sumrem) == remcount.end())
            remcount.insert({sumrem, 1});
        else
            count += remcount[sumrem]++;
    }
    return count;
}

int main()
{
    int n, k;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>k;
    
    cout<<count_subarrays_withsum_divbyK(n, arr, k);
    
    return 0;
}