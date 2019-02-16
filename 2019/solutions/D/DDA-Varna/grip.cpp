#include<bits/stdc++.h>
using namespace std;
int d,m,g,lenuch,lenneuch,len,ds,dos,f=0,dm[14]= {31,31,28,31,30,31,30,31,31,30,31,30,31,31};
int dmp[14]= {0,0,31,59,90,120,151,181,212,243,273,304,334,365};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>d>>m>>g>>lenuch;
    if(g==2020)
    {
        dm[2]=29;
        for(int i=3; i<=13; i++)
        {
            dmp[i]++;
            f=1;
        }
    }
    d+=dmp[m];
    if(g==2019)ds=(d+1)%7;
    if(g==2020)ds=(d+2)%7;
    if(ds<=5)dos=6-ds;
    else dos=0;
    lenneuch=(lenuch/5)*2;
    if(ds==6)lenneuch+=2;
    if(ds==0)lenneuch+=1;
    else if(lenuch%5>=dos)lenneuch+=2;
    len=lenneuch+lenuch;
    d+=len;
    if(g==2020&&d>366)
    {
        g++;
        d-=366;
        for(int i=3; i<=12; i++)
        {
            dmp[i]--;
        }
    }
    if(g==2019&&d>365)
    {
        g++;
        d-=365;
        for(int i=3; i<=12; i++)
        {
            dmp[i]++;
        }
    }
    for(int i=2; i<=13; i++)
    {
        if(d<dmp[i])
        {
            m=i-1;
            d-=dmp[i-1];
            break;
        }
    }
    if(d<10&&m<10)cout<<"0"<<d<<"."<<"0"<<m<<"."<<g<<endl;
    else if(d<10)cout<<"0"<<d<<"."<<m<<"."<<g<<endl;
    else if(m<10)cout<<d<<"."<<"0"<<m<<"."<<g<<endl;
    else cout<<d<<"."<<m<<"."<<g<<endl;
}
