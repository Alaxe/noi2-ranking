#include<iostream>
using namespace std;
int maxdni[14]={31,31,28,31,30,31,30,31,31,30,31,30,31,31};
int main()
{
    int d,m,g,dnivak,dni=0;
    char a;
    cin>>d>>a>>m>>a>>g>>dnivak;
    if((g%4==0&&g%100!=0)||g%400==0)maxdni[2]++;
    for(int i=1; i<m; i++)dni+=maxdni[i];
    dni+=d;
    dni%=7;
    dni++;
    if(dni==8)dni=7;
    for(int i=1; i<=dnivak; i++)
    {
        if(dni==6||dni==7)i--;
        dni++;
        if(dni>7)dni=1;
        d++;
    }
    while(d>maxdni[m])
    {
        d-=maxdni[m];
        m++;
    }
    if(m>12)
    {
        m=1;
        g++;
    }
    if(dni==5)d+=3;
    if(dni==6)d+=2;
    if(d<10)cout<<0;
    cout<<d<<".";
    if(m<10)cout<<0;
    cout<<m<<"."<<g<<endl;
}
