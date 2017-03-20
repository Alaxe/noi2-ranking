#include <iostream>
using namespace std;
int main ()
{
    long long a, br=0, n=0, b, c;
    cin>>a;
    b=a;
    while (a>0)
    {
        a=a/10;
        br++;
    }
    a=b;
    if (br<4)
    {
        c=a%10;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
    }
    if (br<10&&br>3)
    {
        c=a%100;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
    }
    if (br<19&&br>9)
    {
        c=a%1000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
    }
    if (br<35&&br>18)
    {
        c=a%10000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<50&&br>34)
    {
        c=a%100000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<68&&br>49)
    {
        c=a%1000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<96&&br>67)
    {
        c=a%10000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<120&&br>95)
    {
        c=a%100000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<147&&br>119)
    {
        c=a%1000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<187&&br>146)
    {
        c=a%10000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<220&&br>186)
    {
        c=a%100000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<256&&br>219)
    {
        c=a%1000000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<308&&br>255)
    {
        c=a%10000000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<353&&br>307)
    {
        c=a%100000000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<401&&br>352)
    {
        c=a%1000000000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<459&&br>400)
    {
        c=a%10000000000000000;
        while(c!=1)
        {
            c=c/2;
            n++;
        }
        n++;
    }
    if (br<513&&br>458)
    {
        c=a%100000000000000000;
        while(c!=0)
        {
            c=c/2;
            n++;
        }
        n++;
    }

    cout<<n<<endl;
    return 0;
}
