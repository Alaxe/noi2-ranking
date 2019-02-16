#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int dm[14]={31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31};

int format(int d, int m, int g)
{
    int brd=d;
    for(int i=1; i<m; i++) brd+=dm[i];
    return brd;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d, m, g;
    char nakl;
    cin>>d>>nakl>>m>>nakl>>g;
    if(g==2020) dm[2]=29;
    int form=format(d, m, g), ds=(form+1+(g==2020))%7;
    int br;
    cin>>br;
    while(br>5)
    {
        br-=5;
        d+=7;
        if(d>dm[m])
        {
            d-=dm[m];
            m++;
            if(m>12)
            {
                m-=12;
                g++;
                if(g==2020) dm[2]=29;
                else dm[2]=28;
            }
        }
    }
    while(br || ds==0 || ds==6)
    {
        if(ds>0 && ds<6) br--;
        ds++;
        ds%=7;
        d++;
        if(d>dm[m])
        {
            d-=dm[m];
            m++;
            if(m>12)
            {
                m-=12;
                g++;
                if(g==2020) dm[2]=29;
                else dm[2]=28;
            }
        }
    }
    cout<<d/10<<d%10<<"."<<m/10<<m%10<<"."<<g<<endl;
    return 0;
}

