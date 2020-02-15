#include<iostream>
using namespace std;
int main()
{
    long long n;
    int broi;
    cin>>n;
    broi = 0;
    for(long long i=1; i<=n; i++)
    {
        if(i<10) broi = broi + 1;
        if(i>9 && i<100)
        {
            int c1,c2;
            c2 = i/10;
            c1 = i%10;
            if(c1==c2) broi = broi + 1;
        }
        if(i>99 && i<1000)
        {
            int c1,c2,c3;
            c3 = i/100;
            c2 = i/10%10;
            c1 = i%10;
            if(c1==c2 && c2==c3) broi = broi + 1;
        }
        if(i>999 && i<10000)
        {
            int c1,c2,c3,c4;
            c4 = i/1000;
            c3 = i/100%10;
            c2 = i/10%10;
            c1 = i%10;
            if(c1==c2 && c2==c3 && c3==c4) broi = broi + 1;
        }
        if(i>9999 && i<100000)
        {
            int c1,c2,c3,c4,c5;
            c5 = i/10000;
            c4 = i/1000%10;
            c3 = i/100%10;
            c2 = i/10%10;
            c1 = i%10;
            if(c1==c2 && c2==c3 && c3==c4 && c4==c5) broi = broi + 1;
        }
        if(i>99999 && i<1000000)
        {
            int c1,c2,c3,c4,c5,c6;
            c6 = i/100000;
            c5 = i/10000%10;
            c4 = i/1000%10;
            c3 = i/100%10;
            c2 = i/10%10;
            c1 = i%10;
            if(c1==c2 && c2==c3 && c3==c4 && c4==c5 && c5==c6) broi = broi + 1;
        }

    }
    cout<<broi<<endl;
    return 0;
}
