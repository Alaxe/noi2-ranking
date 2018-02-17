#include<bits/stdc++.h>
using namespace std;
char c;
int d1,m1,d2,m2,d3,m3,d4,m4,mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},n,p;
bool flag;
int main()
{
    c='/';
    cin >> d1 >> c >> m1;
    cin >> d2 >> c >> m2;
    cin >> d3 >> c >> m3;
    cin >> d4 >> c >> m4;
    n=0;
    if ( d1==d4 && m1==m4 && d2==d4 && m2==m4 && d3==d4 && m3==m4 )
    {
        d1+=23;
        d2+=28;
        d3+=33;
        n+=33;
        if ( d1>mes[m1] ) { d1-=mes[m1]; m1++; if ( m1>12 ) m1=1; }
        if ( d2>mes[m2] ) { d2-=mes[m2]; m2++; if ( m2>12 ) m2=1; }
        if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
        if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
    }
    else
    {
        while(d1<d4 && m1<m4)
        {
            d1+=23;
            if ( d1>mes[m1] ) { d1-=mes[m1]; m1++; if ( m1>12 ) m1=1; }
        }
        n+=(d1-d4);
        while(d2<d4 && m2<m4)
        {
            d2+=28;
            if ( d2>mes[m1] ) { d2-=mes[m2]; m2++; if ( m2>12 ) m2=1; }
        }
        n+=(d3-d4);
        while(d3<d4 && m3<m4)
        {
            d3+=33;
            if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
        }
        n+=(d3-d4);
    }
    flag=true;
    while(flag)
    {
        while(1)
        {
            d1+=23;
            if ( d1>mes[m1] ) { d1-=mes[m1]; m1++; if ( m1>12 ) m1=1; }
            n+=23;
            if (d1==d2 && d1==d3 && m1==m2 && m1==m3) break;
            d2+=28;
            if ( d2>mes[m2] ) { d2-=mes[m2]; m2++; if ( m2>12 ) m2=1; }
            n+=5;
            if (d1==d2 && d1==d3 && m1==m2 && m1==m3) break;
            d3+=33;
            if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
            if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
            n+=5;
            if (d1==d2 && d1==d3 && m1==m2 && m1==m3) break;
        }
        if ( d1==d4 && m1==m4 && d2==d4 && m2==m4 && d3==d4 && m3==m4 )
        {
            n=33;
            d1+=23;
            d2+=28;
            d3+=33;
            if ( d1>mes[m1] ) { d1-=mes[m1]; m1++; if ( m1>12 ) m1=1; }
            if ( d2>mes[m2] ) { d2-=mes[m2]; m2++; if ( m2>12 ) m2=1; }
            if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
            if ( d3>mes[m3] ) { d3-=mes[m3]; m3++; if ( m3>12 ) m3=1; }
        }
        else flag=false;
    }
    cout << n << endl;
    return 0;
}
/**
1/1 1/1 1/1 1/1

23/7 29/10 23/7 10/2
*/
