#include <iostream>
#include <set>
using namespace std;

void powerful_numbers(int a, int b, int x)
{
    set<int> s;
    bool flag = false;
    int ai = 1, bj = 1;
    while (!flag)
    {
        bj = 1;
        while (true)
        {
            int n = ai + bj;
            if (n <= x)
                s.insert(n);
            else
            {
                if (bj == 1)
                    flag = true;
                break;
            }
            if (b == 1)
                break;
            bj *= b;
        }
        if (a == 1)
            break;
        ai *= a;
    }
    for (int n : s)
        cout << n << " ";
}

int main()
{
    int a, b, x;
    cin >> a >> b >> x;

    powerful_numbers(a, b, x);
}