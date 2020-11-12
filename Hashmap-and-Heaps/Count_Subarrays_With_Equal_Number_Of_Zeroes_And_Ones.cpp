#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count_equal01_subarrays(int n, vector<int> &arr)
{
    unordered_map<int,int> countdiff01;
    int diff = 0, count = 0;
    countdiff01.insert({0,1});
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            diff--;
        else
            diff++;
        if(countdiff01.find(diff) == countdiff01.end())
            countdiff01.insert({diff, 1});
        else
            count += countdiff01[diff]++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<count_equal01_subarrays(n, arr);
    
    return 0;
}
