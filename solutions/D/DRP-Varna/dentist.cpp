#include<bits/stdc++.h>
using namespace std;
struct den
{
    int c;
    int ta;
};
int main()
{
    den pat[1000];
    long long fc=12*60,sumta=0,t,lc=0;
    for ( int i=1 ; i<1000 ; i++ )
    {
        if(cin.eof()){t=i;break;}
        cin>>pat[i].c>>pat[i].ta;
    }
    for ( int i=1 ; i<=t ; i++)
    {
        sumta+=pat[i].ta;
        if(pat[i].c>fc)fc=pat[i].c;
        if(pat[i].c>lc)lc=pat[i].c;
    }
    cout<<fc+sumta-lc;

    return 0;
}
