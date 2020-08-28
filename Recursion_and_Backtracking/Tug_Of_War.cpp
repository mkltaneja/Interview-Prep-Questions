#include<iostream>
#include<vector>
#include<climits>
#define vi vector<int>
using namespace std;

int sum(vi &ar)
{
    int s = 0;
    for(int i : ar)
        s += i;
    return s;
}

vi ans1, ans2;
int minsum = INT_MAX;
void tugOfwar(int idx, int i, int j, vi &a, vi &b, vi &arr)
{
    if(idx == arr.size())
    {
        int sum1 = sum(a);
        int sum2 = sum(b);
        if(abs(sum1 - sum2) < minsum)
        {
            ans1 = a;
            ans2 = b;
            minsum = abs(sum1 - sum2);
        }
        return;
    }
    if(i < a.size())
    {
        a[i] = arr[idx];
        tugOfwar(idx+1, i+1, j, a, b, arr);
        a[i] = 0;
    }
    if(j < b.size())
    {
        b[j] = arr[idx];
        tugOfwar(idx+1, i, j+1, a, b, arr);
        b[j] = 0;
    }
}

int main()
{
    int n;
    cin>>n;
    vi arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    if(n == 1)
    {
        cout<<-1;
        return 0;
    }
    
    vi a(n/2,0), b(n/2,0);
    if(n & 1)
        a.push_back(0);
    // cout<<a.size()<<" "<<b.size()<<endl;
    tugOfwar(0, 0, 0, a, b, arr);
    
    cout<<"[";
    for(int i=0; i<ans1.size()-1; i++)
        cout<<ans1[i]<<", ";
    cout<<ans1[ans1.size()-1]<<"] ";
    cout<<"[";
    for(int i=0; i<ans2.size()-1; i++)
        cout<<ans2[i]<<", ";
    cout<<ans2[ans2.size()-1]<<"]";
}