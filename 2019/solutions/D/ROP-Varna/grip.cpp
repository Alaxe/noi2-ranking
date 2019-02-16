#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int month[15]={31,31,28,31,30,31,30,31,31,30,31,30,31,31};
long long konv(int d,int m,int g)
{
    int i,sum=0;
    if(g==2020)month[2]++;
    for(i=1;i<m;i++)sum+=month[i];
    sum+=d;
    if(g==2020)sum+=365;
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d1,m1,g1,brd,k1,i,w,br=-1,d2,m2,g2,z=0;
    char c;
    cin>>d1>>c>>m1>>c>>g1>>brd;
    if(g1==2019 && m1==12)month[2]++;
    if(g1==2020 && m1>10)month[2]=28;
    k1=konv(d1,m1,g1);

    for(i=k1;;i++)
    {
        if((i+1)%7!=6&&((i+1)%7!=0))br++;
        if(br==brd)break;

    }
    if((i+1)%7==0)i++;
    else if((i+1)%7==6)i+=2;
    g2=(i)/365+2019;
    i-=(g2-2019)*365;
    for(int p=1;;p++)
    {
        i-=month[p];
        if(i<=0){d2=i+month[p];m2=p;break;}
    }
    if(m1==12)d2--;
    if(d2<10)cout<<0;
    cout<<d2<<".";
    if(m2<10)cout<<0;
    cout<<m2<<"."<<g2<<endl;
    return 0;
}
