#include<iostream>
using namespace std;

const long long mod=1073741824;
int m, n, p, q;
int c=0;

long long mem[10124][2]; // n+p=10100

long long f(short lastd, int g)
{
    if(mem[g][lastd]>=0) return mem[g][lastd];

    //cout<<lastd<<" "<<g<<endl;
    if(g>=n)
    {
        return 1;
    }

    long long f1, f2=0;
    f1=f(0, g+p)%mod;

    if(!lastd) f2=f(1, g-q)%mod;

    mem[g][lastd]=f1+f2;
    return mem[g][lastd];
}

int main()
{
    cin>>m>>n>>p>>q;

    for(int i=0;i<10124;i++) { mem[i][0]=(-1); mem[i][1]=(-1); }

    // 0 - in; 1 - out
    long long answer=f(0, m+p);

    cout<<answer<<endl;

    return 0;
}
