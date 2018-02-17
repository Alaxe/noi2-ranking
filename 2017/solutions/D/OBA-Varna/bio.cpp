#include<bits/stdc++.h>
using namespace std;
long long d[5],m[5],m1[4]={0,23,28,33},d1,d2,d3,ost[4],mes[13]={31,31,28,31,30,31,30,31,31,30,31,30,31},i,j;
char c;
int main()
{
    cin>>d[1]>>c>>m[1];
    cin>>d[2]>>c>>m[2];
    cin>>d[3]>>c>>m[3];
    cin>>d[4]>>c>>m[4];

    for (j=1; j<=3; j++)
    {
        if (m[j]<m[4])
        {
            for (i=m[j]; i<m[4];)
            {
                d[j]=d[j]+m1[j];
                if (d[j]>mes[i]) {d[j]=d[j]-mes[i];i++;m[j]++;}
            }
        }
        else if (m[j]>m[4])
        {
            for (i=m[j]; i>m[4];)
            {
                d[j]=d[j]-m1[j];
                if (d[j]<=0) {d[j]=mes[i]+d[j];i--;m[j]--;}
            }
        }
        ost[j]=d[4]-d[j];
        if (ost[j]>0 && ost[j]>m1[j]) {d[j]=d[j]+m1[j];ost[j]=ost[j]-m1[j];}
        else if (ost[j]<0 && ost[j]-(2*ost[j])>m1[j]) {d[j]=d[j]-m1[j];ost[j]=ost[j]+m1[j];}
    }

    if (ost[1]>0) d1=23-ost[1];
    else d1=ost[1]+23;
    if (ost[2]>0) d2=28-ost[2];
    else d2=ost[2]+28;
    if (ost[3]>0) d3=33-ost[3];
    else d3=ost[3]+33;

    while (d1!=d2 || d2!=d3 || d1!=d3)
    {
        d1=d1+23;
        d2=d2+28;
        d3=d3+33;
        while (d1+23<=d3) d1=d1+23;
        while (d2+28<=d3) d2=d2+28;
    }
    cout<<d1<<endl;
    return 0;
}
/**
1/1 1/1 1/1 1/1

21252
////////////////
23/7 29/10 23/7 10/2

10789
*/
