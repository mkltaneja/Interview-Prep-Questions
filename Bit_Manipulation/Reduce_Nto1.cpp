
// METHOD 1 (BFS)
#include<iostream>
#include<queue>
using namespace std;

void minred_bfs(long n)
{
    queue<pair<long,int>> que;
    que.push({n,0});
    while(!que.empty())
    {
        long nn = que.front().first;
        int count = que.front().second;
        que.pop();
        if(nn == 1)
        {
            cout<<count;
            return;
        }
        if(nn & 1)
        {
            que.push({nn-1,count+1});
            que.push({nn+1,count+1});
        }
        else
            que.push({nn/2,count+1});
    }
}

int main()
{
    long n;
    cin>>n;
    minred_bfs(n);
}

////////////////////////////////////////////OR///////////////////////////

// METHOD 2(Pattern observation)
#include<iostream>
#include<queue>
using namespace std;

void minred(long n)
{
    int count = 0;
    while(n != 1)
    {
        if((n & 1) == 0)
            n /= 2;
        else if(n == 3)
            n--;
        else if(n % 4 == 1)  // or if((n & 3) == 1) --> faster
            n--;
        else if(n % 4 == 3)  // or if((n & 3) == 3) --> faster
            n++;
        count++;
    }
    cout<<count;
}

int main()
{
    long n;
    cin>>n;
    minred(n);
}