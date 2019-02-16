#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int dm[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int d,m,y,k,br=0,ds=1;
    char zn1,zn2;
    cin>>d>>zn1>>m>>zn2>>y>>k;
    if(y==2020){dm[2]=29;ds=3;}
    else ds=2;
    for(int i=1;i<m;i++)ds+=dm[i];
    ds=(ds+d)%7-1;
    if(ds==-1)ds=6;
    if(ds==0||ds==6)br--;
    while(br<k)
    {
        ds=(ds+1)%7;
        d++;
        if(d>dm[m])
        {
            d%=dm[m];
            m++;
            if(m>12){m=1;y++;}

        }
    if(ds!=0&&ds!=6)br++;
    }
cout<<d/10<<d%10<<"."<<m/10<<m%10<<"."<<y<<endl;
return 0;
}
