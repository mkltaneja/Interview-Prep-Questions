#include<iostream>
#include<vector>
using namespace std;

void combinations_2(int item, int idx, int n, int m, vector<char> &boxes)
{
    if(item == m+1)
    {
        for(char c : boxes)
            cout<<c;
        cout<<endl;
        return;
    }
    for(int i=idx; i<n; i++)
    {
        boxes[i] = 'i';
        combinations_2(item + 1, i + 1, n, m, boxes);
        boxes[i] = '-';
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<char> boxes(n);
    for(int i=0; i<n; i++)
        boxes[i] = '-';
    combinations_2(1, 0, n, m, boxes);
}