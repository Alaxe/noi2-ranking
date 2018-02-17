#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m[10],d[10],t[10],tm[10]={0},month[12]={31,28,31,30,31,30,31,31,30,31},i,j,mn=1000000,mc[10];
    int s;
    char c;
    cin>>d[0]>>c>>m[0]>>d[1]>>c>>m[1]>>d[2]>>c>>m[2]>>d[3]>>c>>m[3];
    for(i=0;i<4;i++)
    {
        for(j=0;j<m[i]-1;j++)
        {
            tm[i]+=month[j];
        }
        tm[i]+=d[i];
    }
    mc[0]=tm[0]%23;
    if(mc[0]==0)mc[0]=23;
    mc[1]=tm[1]%28;
    if(mc[1]==0)mc[1]=28;
    mc[2]=tm[2]%33;
    if(mc[2]==0)mc[2]=33;
    for(i=1;;i++)
    {
        if((((i*33)+mc[2])-mc[1])%28==0 && (((i*33)+mc[2])-mc[0])%23==0){cout<<i*33+mc[2]-tm[3]<<endl;return 0;}
    }
}
/**
1/1 1/1 1/1 1/1

23/7 29/10 23/7 10/2
*/
