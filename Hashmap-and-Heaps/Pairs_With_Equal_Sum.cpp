#include<iostream>
#include<set>
#include<vector>
using namespace std;

bool is_equalsumpair(int n, vector<int> &arr)
{
    set<int> psum;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if(psum.find(sum) != psum.end())
                return true;
            psum.insert(sum);
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<(boolalpha)<<is_equalsumpair(n, arr);
}