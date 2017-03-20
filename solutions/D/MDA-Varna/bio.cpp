#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d[5],me[5];
char c[4];
int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int sum( int j, int k )
{
    int s =0,i=j;
    while( 1 )
    {
        if( i == k ) break;
        if( i > 12 ) i = 1 ;
        s += m[i];
    }
    return s ;
}
void read()
{
    cin >> d[0] >> c[0] >> me[0] ;
    cin >> d[1] >> c[1] >> me[1] ;
    cin >> d[2] >> c[2] >> me[2] ;
    cin >> d[3] >> c[3] >> me[3] ;
}
void date()
{
    int p = 82,i=me[3];

    while( p )
    {
        if( i > 12 ) i = 1;
        if( i == me[3] )
           {p -= (m[i-1]-d[3]-1);}
        if( m[i] > p )
            {d[4] = p;break;}
        else
            p -= (m[i-1]+1);
        i ++ ;
    }
    if(p == 0) d[4] = 1 ;
    m[4] = i+1 ;
}
int f_d( int p )
{
    int dni=0;
    dni = (m[me[p]] - d[p]);
    dni += d[4];
    return dni;

}
void solve()
{
    if( d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[3] == d[4] && me[0] == me[1] && me[1] == me[2] && m[2] == m[3] && m[3] == m[4] ) cout << 21252 << endl;
}
int main()
{
    read();
    date();
    solve() ;

}
/*
23/7
29/10 23/7 10/2*/
