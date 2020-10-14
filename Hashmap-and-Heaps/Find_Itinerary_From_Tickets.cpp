#include <iostream>
#include <unordered_map>
#define f first
#define s second
using namespace std;

void findItinerary(string src, unordered_map<string, string> &sd)
{
    if (sd[src].empty())
    {
        cout << src << ".";
        return;
    }
    cout << src << " -> ";
    findItinerary(sd[src], sd);
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> sd;
    unordered_map<string, bool> pstart;
    for (int i = 0; i < n; i++)
    {
        string s, d;
        cin >> s >> d;
        sd.insert({s, d});
        pstart[d] = false;
        if (pstart.find(s) == pstart.end())
            pstart[s] = true;
    }
    string start;
    for (auto itr : pstart)
    {
        if (itr.s)
        {
            start = itr.f;
            break;
        }
    }

    findItinerary(start, sd);
}