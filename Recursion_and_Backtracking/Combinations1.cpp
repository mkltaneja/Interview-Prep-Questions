#include<iostream>
#include<vector>
using namespace std;

void combinations(int items, int idx, int n, int m, vector<char> &boxes)
{
    if(items == m+1)
    {
        for(char i : boxes)
        {
            if(i == NULL)
                cout<<'-';
            else
                cout<<i;
        }
        cout<<endl;
    }
    for(int i=idx; i<n; i++)
    {
        if(boxes[i] == NULL)
        {
            boxes[i] = 'i';
            combinations(items+1, i+1, n, m, boxes);
            boxes[i] = NULL;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<char> boxes(n);
    combinations(1, 0, n, m, boxes);
}