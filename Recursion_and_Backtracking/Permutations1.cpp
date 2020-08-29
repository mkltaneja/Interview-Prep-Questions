#include<iostream>
#include<vector>
using namespace std;

void permutations(int item, int n, int m, vector<int> &boxes)
{
    if(item == m+1)
    {
        for(int i : boxes)
            cout<<i;
        cout<<endl;
    }
    for(int i=0; i<n; i++)
    {
        if(boxes[i] == 0)
        {
            boxes[i] = item;
            permutations(item+1, n, m, boxes);
            boxes[i] = 0;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> boxes(n,0);
    permutations(1, n, m, boxes);
}