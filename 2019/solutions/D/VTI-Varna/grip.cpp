#include<bits/stdc++.h>
using namespace std;
int allmes[15]= {0,0,31,59,90,120,151,181,212,243,273,304,334,365};
int dnimax[15]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int d,m,god,dni,alldni,svac;
    char c;
    cin>>d>>c>>m>>c>>god>>dni;
    if(god==2019)alldni=allmes[m]+d;
    else
    {
        if(m>2)alldni=allmes[m]+d+366;
        else alldni=allmes[m]+d+365;
        dnimax[2]++;
    }
    if(dni<(6-alldni%7))
    {
        d+=dni;
        if((d+allmes[m])%7>4)d+=7-((d+allmes[m])%7);
        if(d>dnimax[m])
        {
            m++;
            if(m>12)
            {
                god++;
            }
            d=d-dnimax[m-1];
        }
        if(d<10)
        {
            if(m<10)
            {
                cout<<"0"<<d<<".0"<<m<<"."<<god<<endl;
            }
            else
            {
                cout<<"0"<<d<<".0"<<m<<"."<<god<<endl;
            }
        }
        else
        {
            if(m<10)
            {
                cout<<d<<".0"<<m<<"."<<god<<endl;
            }
            else
            {
                cout<<d<<"."<<m<<"."<<god<<endl;
            }

        }
    }
    else
    {
        dni-=5-alldni%7;
        d+=5-alldni%7;
        if(alldni%7==5)dni++;
        svac=dni/5;
        d+=svac*7;
        d+=dni%5;
        while(d>dnimax[m])
        {
            m++;
            if(m>12)
            {
                god++;
            }
            d=d-dnimax[m-1];
        }
        if((d+allmes[m])%7>4)d+=7-((d+allmes[m])%7);
        if(d<10)
        {
            if(m<10)
            {
                cout<<"0"<<d<<".0"<<m<<"."<<god<<endl;
            }
            else
            {
                cout<<"0"<<d<<".0"<<m<<"."<<god<<endl;
            }
        }
        else
        {
            if(m<10)
            {
                cout<<d<<".0"<<m<<"."<<god<<endl;
            }
            else
            {
                cout<<d<<"."<<m<<"."<<god<<endl;
            }

        }
    }
}
