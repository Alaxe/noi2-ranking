#include <cstdio>
#include <iostream>

using namespace std;

int p;
long long x, b, z, y, br, ttt, ans;

int main ()
{
    //freopen("i3.txt", "r", stdin);
    scanf("%d", &p);
    for(int tt=0; tt<4; ++tt)
    {
        scanf("%lld", &x);
        ans=1000000000000000000LL;
        if(x%9!=0)
        {
            printf("0\n");
            continue;
        }
        x/=9;
        for(int dig=1; dig<=9; ++dig)
        {
            b=dig;
            ttt=18;
            while(ttt--)
            {
                z=x+b;
                y=z;
                br=0;
                while(y>0)
                {
                    y/=10;
                    br++;
                }
                y=dig;
                while(br--)
                {
                    y*=10;
                }
                if(z*10+dig-y-z==9*x)
                {
                    ans=min(ans, y+z);
                    break;
                }
                b*=10;
                b+=dig;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}