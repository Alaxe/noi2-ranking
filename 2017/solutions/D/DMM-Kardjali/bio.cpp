#include<iostream>
using namespace std;
struct date
{int den;
int mes;
};
date fi,em,ph,d;
int main(){
    char s;
    int ma,max,q=0,w=0,v=0,t=0,de=0;
    cin>>fi.den>>s>>fi.mes>>em.den>>s>>em.mes>>ph.den>>s>>ph.mes>>d.den>>s>>d.mes;
    int f=0,e=0,p=0,b1[16],b2[14],b3[12];

    for(int i=1;i<fi.mes;i++)
    {if(i==1 || i==3 || i==5 ||i==7 || i==8 || i==10 || i==12) f+=31;
    if(i==4 || i==6 || i==9 ||i==11) f+=30;
    if(i==2) f+=28;}
    f+=fi.den;
    for(int i=1;i<em.mes;i++)
    {if(i==1 || i==3 || i==5 ||i==7 || i==8 || i==10 || i==12) e+=31;
    if(i==4 || i==6 || i==9 ||i==11) e+=30;
    if(i==2) e+=28;}
    e+=em.den;
    for(int i=1;i<ph.mes;i++)
    {if(i==1 || i==3 || i==5 ||i==7 || i==8 || i==10 || i==12) p+=31;
    if(i==4 || i==6 || i==9 ||i==11) p+=30;
    if(i==2) p+=28;}
    p+=ph.den;
    for(int i=1;i<d.mes;i++)
    {if(i==1 || i==3 || i==5 ||i==7 || i==8 || i==10 || i==12) de+=31;
    if(i==4 || i==6 || i==9 ||i==11) de+=30;
    if(i==2) de+=28;}
    de+=d.den;

    b1[0]=f%23;
    b2[0]=e%28;
    b3[0]=p%33;

    while(b1[q]<365)
    {b1[q+1]=b1[q]+23;
    q++;
    }
    while(b2[w]<365)
    {b2[w+1]=b2[w]+28;
    w++;

    }
    while(b3[t]<365)
    {b3[t+1]=b3[t]+33;
    t++;
    }
    for(int i=0;i<q;i++)
    {
    for(int j=0;j<w;j++)
    {
    for(int h=0;h<t;h++)
    {if(b2[j]==b3[h]) {v=b1[i];}
    }}}
    if(de>v) cout<<21252-de<<endl;
    else cout<<v-de<<endl;

return 0;
}
