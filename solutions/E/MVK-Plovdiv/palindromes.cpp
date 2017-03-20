#include<iostream>
using namespace std;
int main()
{
    long long n, p, ma = 0, mb = 0, mp = 0, k[6];
    cin >> n;
    for(long long a = 1; a <= n; a++)
    {
        for(long long b = a; b <= n; b++)
        {
            p = a*b;
            if(p<10)
            {
                p = p;
                if(mp<p)
                {
                    mp = p;
                    ma = a;
                    mb = b;
                }
            }
            if(p<100&&p>9&&p%11==0)
            {
                if(mp<p)
                {
                    mp = p;
                    ma = a;
                    mb = b;
                }
            }
            if(p<1000&&p>99)
            {
                k[0] = p / 100;
                k[1] = p % 10;
                if(k[0]==k[1])
                {
                    if(mp<p)
                    {
                        mp = p;
                        ma = a;
                        mb = b;
                    }
                }

            }
            if(p<10000&&p>999)
            {
                k[0] = p / 1000;
                k[1] = p % 10;
                k[2] = p / 100 % 10;
                k[3] = p / 10 % 10;
                if(k[0]==k[1]&&k[2]==k[3])
                {
                    if(mp<p)
                    {
                        mp = p;
                        ma = a;
                        mb = b;
                    }
                }
            }
            if(p<100000&&p>9999)
            {
                k[0] = p / 10000;
                k[1] = p % 10;
                k[2] = p / 1000 % 10;
                k[3] = p / 10 % 10;
                if(k[0]==k[1]&&k[2]==k[3])
                {
                    if(mp<p)
                    {
                        mp = p;
                        ma = a;
                        mb = b;
                    }
                }
            }
            if(p<1000000&&p>99999)
            {
                k[0] = p / 100000;
                k[1] = p / 10000 % 10;
                k[2] = p / 1000 % 10;
                k[3] = p / 100 % 10;
                k[4] = p / 10 % 10;
                k[5] = p % 10;
                if(k[0]==k[5]&&k[1]==k[4]&&k[2]==k[3])
                {
                    if(mp<p)
                    {
                        mp = p;
                        ma = a;
                        mb = b;
                    }
                }
            }
        }
    }
    cout << ma << " " << mb << endl << mp << endl;
    return 0;
}
