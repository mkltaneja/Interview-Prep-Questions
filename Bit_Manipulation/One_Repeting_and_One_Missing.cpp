#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    
    int missrep = 0;
    for(int i=0; i<n; i++)
        missrep ^= nums[i] ^ (i+1);
    int rsb = (missrep & -missrep);
    int miss = 0, rep = 0;
    for(int i=0; i<n; i++)
    {
        if(i & rsb)
            miss ^= (i+1);
        else
            rep ^= (i+1);
        if(nums[i] & rsb)
            miss ^= nums[i];
        else
            rep ^= nums[i];
    }
    for(int i : nums)
    {
        if(i == miss)
        {
            miss = rep;
            rep = i;
            break;
        }
    }
    cout<<"Missing Number -> "<<miss<<endl;
    cout<<"Repeating Number -> "<<rep<<endl;
}