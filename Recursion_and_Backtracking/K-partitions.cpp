#include<iostream>
#include<vector>
using namespace std;

int base = 1;
void display(vector<vector<int>> &set)
{
    cout<<base++<<". ";
    for(vector<int> ar : set)
    {
        cout<<"[";
        for(int i=0; i<ar.size()-1; i++)
            cout<<ar[i]<<", ";
        cout<<ar[ar.size()-1]<<"] ";
    }
    cout<<endl;
}

void Kpartitions(int n, int N, int k, int K, vector<vector<int>> &set)
{
    if(n < k)
        return;
        
    if(n == N+1)
    {
        if(k == K)
            display(set);
        return;
    }
        
    for(int i=0; i<set.size(); i++)
    {
        if(set[i].size() == 0)
        {
            set[i].push_back(n);
            Kpartitions(n+1, N, k+1, K, set);
            set[i].pop_back();
            break;
        }
        else
        {
            set[i].push_back(n);
            Kpartitions(n+1, N, k, K, set);
            set[i].pop_back();
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> set(k,vector<int>());
    Kpartitions(1,n,0,k,set);
}