#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int Largest_Subarray(int n, vector<int> &arr)
{
    int maxlen = 0;
    unordered_map<int, int> sumatpos;
    int sum = 0;
    sumatpos.insert({sum,-1});
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sumatpos.find(sum) == sumatpos.end())
            sumatpos.insert({sum,i});
        else
            maxlen = max(maxlen, i - sumatpos[sum]);
    }
    return maxlen;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << Largest_Subarray(n, arr);

    return 0;
}