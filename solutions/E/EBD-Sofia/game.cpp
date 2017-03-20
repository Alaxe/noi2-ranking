#include<iostream>
using namespace std;
int main()
{int m,k,sbor=0,newi=1;
int a[200];
cin>>m>>k;
int g=1;
for(int i=1; i<=200;i++)
{if (sbor<=k){
    cin>>a[i];
    if(a[i]%2==0)
    {
        sbor=sbor+a[i];
    }
    g++;}
}
int raz;
if(m-a[1]<=a[1]-m)
    {
    raz=m-a[1];
    }
    else
    {
        raz=a[1]-m;
}
for(int h=1;h<g;h++)
{
    if(m-a[h]<=raz)
    {
    newi=h+1;
    raz=m-a[h];

    }
    else if(a[h]-m<=raz)
    {
        raz=a[h]-m;
        newi=h+1;

    }
}
cout<<newi<<" "<<sbor;
    return 0;
}
