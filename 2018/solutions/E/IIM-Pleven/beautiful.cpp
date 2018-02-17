#include <iostream>
using namespace std;

long long n,k,i,Min;

int main ()
{
    cin>>n>>k;
    Min=9999999999999999999999999999999999999999999999999999999999;
    if (n==1)
    {
        for (i=1; i<=9; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
        if (n==2)
    {
        for (i=10; i<=99; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==3)
    {
        for (i=100; i<=999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==4)
    {
        for (i=1000; i<=9999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==5)
    {
        for (i=10000; i<=99999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==6)
    {
        for (i=100000; i<=999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==7)
    {
        for (i=1000000; i<=9999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==8)
    {
        for (i=10000000; i<=99999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==9)
    {
        for (i=100000000; i<=999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==10)
    {
        for (i=1000000000; i<=9999999999; i++)
        {
            if (i%k==0)
            {
               if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==11)
    {
        for (i=10000000000; i<=99999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==12)
    {
        for (i=100000000000; i<=999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==13)
    {
        for (i=1000000000000; i<=9999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==14)
    {
        for (i=10000000000000; i<=99999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==15)
    {
        for (i=100000000000000; i<=999999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==16)
    {
        for (i=100000000000000; i<=9999999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==17)
    {
        for (i=1000000000000000; i<=99999999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    if (n==18)
    {
        for (i=10000000000000000; i<=999999999999999999; i++)
        {
            if (i%k==0)
            {
                if (Min>i)
                {
                    Min=i;
                }
            }
        }
    }
    cout<<Min;

    return 0;
}
