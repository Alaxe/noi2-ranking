#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

long long base[2]={3456793,2345699};
long long mod[2]={100000000003,1000000000039};

int w,k;

long long output=0;
int n,inp[nmax];

int step;

long long hsh[2];

map< pair<long long/*hash_1*/,long long/*hash_2*/>,int > seen;

void add(int which,int val)
{
    hsh[which]=(hsh[which]*base[which]+(val+1))%mod[which];
}

long long DISCARD_VALUE[2];
void discard(int which,int val)
{
    hsh[which]=(hsh[which]-DISCARD_VALUE[which]*(val+1))%mod[which];
    hsh[which]=(hsh[which]+mod[which])%mod[which];
}

void run()
{
    hsh[0]=0;
    hsh[1]=0;

    if(w==1)
    {
        int started=1;
        for(int i=1;i<=n;i++)
        {
            add(0,inp[i]);
            add(1,inp[i]);

            if(i-k>=1)discard(0,inp[i-k]);
            if(i-k>=1)discard(1,inp[i-k]);

            if(inp[i-1]>=inp[i])started=i;
            if(i-started+1>=k)
            {
                pair<long long/*hash_1*/,long long/*hash_2*/> current={hsh[0],hsh[1]};
                if(step==0)seen[current]++;
                else output=output+seen[current];
            }
        }
    }
    if(w==2)
    {
        int started=1;
        for(int i=1;i<=n;i++)
        {
            add(0,inp[i]);
            add(1,inp[i]);

            if(i-k>=1)discard(0,inp[i-k]);
            if(i-k>=1)discard(1,inp[i-k]);

            if(inp[i-1]!=inp[i])started=i;
            if(i-started+1>=k)
            {
                pair<long long/*hash_1*/,long long/*hash_2*/> current={hsh[0],hsh[1]};
                if(step==0)seen[current]++;
                else output=output+seen[current];
            }
        }
    }
}

long long slow_mult(long long a,long long b,long long m)
{
    long long ret=0;
    while(b)
    {
        if(b%2)ret=(ret+a)%m;
        a=(a+a)%m;
        b=b/2;
    }
    return ret;
}
long long slow_pow(long long a,int b,long long m)
{
    long long ret=1;
    while(b)
    {
        if(b%2)ret=slow_mult(ret,a,m);
        a=slow_mult(a,a,m);
        b=b/2;
    }
    return ret;
}
int main()
{
    scanf("%i%i",&w,&k);
    DISCARD_VALUE[0]=slow_pow(base[0],k,mod[0]);
    DISCARD_VALUE[1]=slow_pow(base[1],k,mod[1]);

    for(step=0;step<2;step++)
    {
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

        run();
    }

    printf("%lld\n",output);
    return 0;
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/

