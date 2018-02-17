#include<iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    for(int i=1;i<=12;i++) months[i]+=months[i-1];
    int d1,d2,d3,d;
    int m1,m2,m3,m;
    scanf("%d/%d %d/%d %d/%d %d/%d",&d1,&m1,&d2,&m2,&d3,&m3,&d,&m);
    d1+=months[m1-1];
    d2+=months[m2-1];
    d3+=months[m3-1];
    d+=months[m-1];
    int x=min(d,min(d1,min(d2,d3)));
    d-=x;
    d1-=x;
    d2-=x;
    d3-=x;
    if(d1==d2&&d2==d3) d1+=23; d2+=28; d3+=33;
    for(int i=d1;;i+=23)
    {
        if((i-d2)%28==0&&(i-d3)%33==0){d1=i;break;}
    }
    x=d1-d;
    if(x>21252) x-=21252;
    cout<<x<<endl;
    return 0;
}
