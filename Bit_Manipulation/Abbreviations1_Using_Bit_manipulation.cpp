#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    int msbat = (1 << n);
    // cout<<n<<" "<<msbat<<endl;
    for(int num = 0; num < msbat; num++)
    {
        string pat = "";
        int countz = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int mask = (1 << i);
            if(num & mask)
                countz++;
            else
            {
                if(countz > 0)
                {
                    pat += to_string(countz);
                    countz = 0;
                }
                pat += s[n-i-1];
            }
        }
        if(countz > 0)
            pat += to_string(countz);
        cout<<pat<<endl;
    }
    
    return 0;
}