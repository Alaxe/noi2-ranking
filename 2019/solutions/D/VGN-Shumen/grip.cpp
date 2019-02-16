#include<iostream>
using namespace std;
int dnivm[16];
int main()
{
dnivm[1]=31;
dnivm[3]=31;
dnivm[5]=31;
dnivm[7]=31;
dnivm[8]=31;
dnivm[10]=31;
dnivm[12]=31;
dnivm[4]=30;
dnivm[6]=30;
dnivm[9]=30;
dnivm[11]=30;
dnivm[13]=31;
dnivm[15]=31;
int d,m,g,dv;
char c1,c2;
cin>>d>>c1>>m>>c2>>g>>dv;
int gn,datan,m1=m,sumd=0;
switch(g)
{
    case 2019:gn=2;dnivm[2]=28;dnivm[14]=29;break;
    case 2020:gn=3;dnivm[2]=29;dnivm[14]=28;break;
}
sumd+=d;
m1--;
while(m1>=1)
{
    sumd+=dnivm[m1];
    m1--;
}
datan=((sumd-1)%7)+gn;
int id=datan;
int dnivakanciq=0;
while(dv!=0)
{
    if(id==6||id==7)
    {
        if(id==7)
        {
            dnivakanciq++;
            id=1;
        }
        else
        {
            dnivakanciq+=2;
            id=1;
        }
    }
    else
    {
        dnivakanciq++;
        dv--;
        id++;
    }
}
if(id==6)dnivakanciq+=2;
int dd=d+dnivakanciq;
if(dd>dnivm[m])
{
    do
    {
        dd-=dnivm[m];
        m++;
    }while(dd-dnivm[m]>dnivm[m+1]);
}
if(m>12)
{
    m-=12;
    g++;
}
if(dd<10)cout<<"0";
cout<<dd<<".";
if(m<10)cout<<"0";
cout<<m<<".";
cout<<g<<endl;
return 0;
}
