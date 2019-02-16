#include<iostream>
#include<algorithm>
#define MAN 200001
using namespace std;
struct rebra
{
    int a,b;
} rib[MAN];
bool mark[MAN];
int n,gn,dn,pgn1=0,pdn1=0,pmax=0;
void sela(int orr,int dr);
int main()
{
    int i,j;
    cin>>n;
    for(i=0; i<n-1; i++)
    {
        cin>>rib[i].a>>rib[i].b;
    }
    for(j=1; j<=n; j++)
    {
        mark[j]=0;
    }
    cin>>gn>>dn;
    mark[gn]=1;
    mark[dn]=1;
    sela(1,gn);
    cout<<pmax;
    return 0;
}
void sela(int orr,int dr)
{
    mark[dr]=1;
    if(orr)
        pgn1++;
    else
        pdn1++;
    for(int j=0; j<n-1; j++)
    {
        if(rib[j].a==dr||rib[j].b==dr)
        {
            if(rib[j].a==dr&&!mark[rib[j].b])
            {
                sela(orr,rib[j].b);
                mark[rib[j].b]=0;
                if(orr)
                    pgn1--;
                else
                    pdn1--;
            }
            else if(rib[j].b==dr&&!mark[rib[j].a])
            {
                sela(orr,rib[j].a);
                mark[rib[j].a]=0;
                if(orr)
                    pgn1--;
                else
                    pdn1--;
            }

        }
    }
    if(orr)
    {
        sela(0,dn);
        pdn1--;
    }
    else
    {
        if(pgn1==pdn1&&pgn1>pmax)
            pmax=pgn1;
    }
}
