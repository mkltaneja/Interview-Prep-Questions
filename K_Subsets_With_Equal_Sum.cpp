#include<iostream>
#include<vector>
using namespace std;

bool issumsame(int k, vector<int> &subsum)
{
    for(int i=1; i<k; i++)
        if(subsum[i] != subsum[i-1])
            return false;
    return true;
}

void display(int k, vector<vector<int>> &set)
{
    for(int i=0 ; i<k; i++)
    {
        cout<<"[";
        for(int j=0; j<set[i].size()-1; j++)
            cout<<set[i][j]<<", ";
        cout<<set[i][set[i].size()-1]<<"] ";
    }
    cout<<endl;
}

void ksubequalsum(int idx, int k, int n, int K, vector<int> &arr, vector<int> &subsum, vector<vector<int>> &set)
{
    if(idx == n)
    {
        if(k == K)
        {
            if(issumsame(K,subsum))
                display(K,set);
        }
        return;
    }
    for(int i=0; i<K; i++)
    {
        if(set[i].size() == 0)
        {
            set[i].push_back(arr[idx]);
            subsum[i] += arr[idx];
            ksubequalsum(idx+1, k+1, n, K, arr, subsum, set);
            subsum[i] -= arr[idx];
            set[i].pop_back();
            break;
        }
        else
        {
            set[i].push_back(arr[idx]);
            subsum[i] += arr[idx];
            ksubequalsum(idx+1, k, n, K, arr, subsum, set);
            subsum[i] -= arr[idx];
            set[i].pop_back();
        }
    }
}

int main()
{
    int n, k, sum = 0;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    cin>>k;
    
    if(k == 1)
    {
        cout<<"[";
        for(int i=0; i<n-1; i++)
            cout<<arr[i]<<", ";
        cout<<"] ";
        return 0;
    }
    if(n % k != 0 || k > n)
    {
        cout<<"-1";
        return 0;
    }
    vector<vector<int>> set(k,vector<int>());
    vector<int> subsum(k,0);
    ksubequalsum(0,0,n,k,arr,subsum,set);
}