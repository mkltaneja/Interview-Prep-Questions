// #include<iostream>
// #include<vector>
// using namespace std;

// void combinations(int items, int idx, int n, int m, vector<char> &boxes)
// {
//     if(items == m+1)
//     {
//         for(char i : boxes)
//         {
//             if(i == NULL)
//                 cout<<'-';
//             else
//                 cout<<i;
//         }
//         cout<<endl;
//     }
//     for(int i=idx; i<n; i++)
//     {
//         if(boxes[i] == NULL)
//         {
//             boxes[i] = 'i';
//             combinations(items+1, i+1, n, m, boxes);
//             boxes[i] = NULL;
//         }
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<char> boxes(n);
//     combinations(1, 0, n, m, boxes);
// }

///////////////////////////////////////////////OR////////////////////////////////////////////////

// By Subsequence#include<iostream>
#include<vector>
using namespace std;

void combinations_subseq(int idx, int n, int m, vector<char> &boxes)
{
    if(idx == n)
    {
        int count = 0;
        for(char c : boxes)
            if(c == 'i')
                count++;
        // cout<<count<<endl;
        if(count == m)
        {
            for(char c : boxes)
                cout<<c;
            cout<<endl;
        }
        return;
    }

    boxes[idx] = 'i';
    combinations_subseq(idx+1, n, m, boxes);
    boxes[idx] = '-';
    
    combinations_subseq(idx+1, n, m, boxes);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<char> boxes(n);
    for(int i=0; i<n; i++)
        boxes[i] = '-';
    combinations_subseq(0, n, m, boxes);
}

/////////////////////////////////////////////////////OR////////////////////////////////////////////////

// Subsequence --> using string instead of vector
#include<iostream>
#include<vector>
using namespace std;

void combinations_subseq(int idx, int is, int n, int m, string ans)
{
    if(idx == n)
    {
        if(is == m)
            cout<<ans<<endl;
        return;
    }

    combinations_subseq(idx+1, is+1, n, m, ans+'i');
    combinations_subseq(idx+1, is, n, m, ans+'-');
}

int main()
{
    int n,m;
    cin>>n>>m;
    combinations_subseq(0, 0, n, m, "");
}