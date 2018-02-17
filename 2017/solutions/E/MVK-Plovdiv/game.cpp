#include<iostream>
using namespace std;
int main()
{
    long long m, k, a, sb = 0, msb = 0, r, mr = 9999999, br = 0;
    cin >> m >> k;
    for(long long i = 1; i > 0; i++)
    {
        cin >> a;
        if(a>m)
            r = a - m;
        else
            r = m - a;
        if(mr>=r)
        {
            br = i;
            mr = r;
        }
        if(a%2==0)
        {
            sb+=a;
            if(sb>k)
            {
                cout << br << " " << sb << endl;
                break;
            }
        }
        msb = sb;
        if(i==200)
            break;
    }
    return 0;
}
