#include <bits/stdc++.h>
using namespace std;
long long mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long d1,m1,d2,m2,d3,m3,d4,m4,t1,t2,t3,t4,k;
char s;
int main()
{
    cin>>d1>>s>>m1>>d2>>s>>m2>>d3>>s>>m3>>d4>>s>>m4;
    for( int i=1 ; i<m1 ; i++ )
    {
        t1+=mes[i];
    }
    for ( int i=1 ; i<m2 ; i++)
    {
        t2+=mes[i];
    }
    for ( int i=1 ; i<m3 ; i++)
    {
        t3+=mes[i];
    }
    for ( int i=1 ; i<m4 ; i++ )
    {
        t4+=mes[i];
    }
    t1+=d1;
    ///cout<<t1<<endl;
    t2+=d2;
    ///cout<<t2<<endl;
    t3+=d3;
    ///cout<<t3<<endl;
    t4+=d4;
    ///cout<<t4<<endl;
    k=t1;

    for ( int i=0 ; i<=5000 ; i++)
    {
        k+=23;
        if((k-t2)%28==0)
        {
            if((k-t3)%33==0){cout<<k-t4<<endl;break;}
        }
    }
    return 0;
}
/**
Пример 1
Вход:
1/1 1/1 1/1 1/1
Изход:
21252

Пример 2
Вход:
23/7 29/10 23/7 10/2

Изход:
10789

*/
