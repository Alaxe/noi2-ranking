#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int day(int m1,int y1)
{
    switch(m1)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:return 31;
        case 4:
        case 6:
        case 9:
        case 11:return 30;
        case 2:if(y1%400==0||y1%4==0&&y1%100!=0)return 29;else return 28;
    }
}
int main()
{
    int d,m,y,c;
    cin>>d>>m>>y>>c;
    int days=day(m,y);
    d+=c;
    if(c>7)d=d+((c/2)-1);
    if(c==7)d++;
    if(d>days)
    {
        d=d-days+1;
        m++;
    }
    if(m>12)
    {
        m=1;
        y++;
    }
    if(d<10)cout<<0;
    cout<<d<<".";
    if(m<10)cout<<0;
    cout<<m<<"."<<y<<endl;


return 0;
}
