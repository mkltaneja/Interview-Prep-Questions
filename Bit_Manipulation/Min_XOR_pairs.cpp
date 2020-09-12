
// METHOD 1 --> O(n^2)
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int minxor = INT_MAX;
    vector<pair<int,int>> ans;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int xorn = arr[i] ^ arr[j];
            if(xorn < minxor)
            {
                minxor = xorn;
                ans.clear();
                ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
            }
            else if(xorn == minxor)
                ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
        }
    }
    for(pair<int,int> p : ans)
        cout<<p.first<<", "<<p.second<<endl;
    return 0;
}

// METHOD 2 --> O(n*logn)
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr, arr+n);
    
    int minxor = INT_MAX;
    vector<pair<int,int>> ans;
    for(int i=0; i<n-1; i++)
    {
        int xorn = arr[i] ^ arr[i+1];
        if(xorn < minxor)
        {
            minxor = xorn;
            ans.clear();
            ans.push_back({min(arr[i], arr[i+1]), max(arr[i], arr[i+1])});
        }
        else if(xorn == minxor)
            ans.push_back({min(arr[i], arr[i+1]), max(arr[i], arr[i+1])});
    }
    for(pair<int,int> p : ans)
        cout<<p.first<<", "<<p.second<<endl;
    return 0;
}