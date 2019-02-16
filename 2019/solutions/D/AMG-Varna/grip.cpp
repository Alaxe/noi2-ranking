#include<iostream>
using namespace std;
int main()
{
    int d,m,y,brd,d2=0,m2=0,y2=0;
    cin>>d>>m>>y>>brd;
    brd=brd+(brd/5)*2;
    if(y==2019)
    {
        if(m==4||m==6||m==9||m==11)
        {
            if(brd+d>30) d2=(brd+d)-30, m2=m+1, y2=y;
            else if(brd+d==30) d2=30, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else if(m==1||m==3||m==5||m==7||m==8||m==10)
        {
            if(brd+d>31) d2=(brd+d)-31, m2=m+1, y2=y;
            else if(brd+d==31) d2=31, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else if(m==12)
        {
            if(brd+d>31) d2=(brd+d)-31, m2=1, y2=y+1;
            else if(brd+d==31) d2=31, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else
        {
            if(brd+d>28) d2=(brd+d)-28, m2=m+1, y2=y;
            else if(brd+d==28) d2=28, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
    }
    else
    {
        if(m==4||m==6||m==9||m==11)
        {
            if(brd+d>30) d2=(brd+d)-30, m2=m+1, y2=y;
            else if(brd+d==30) d2=30, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else if(m==1||m==3||m==5||m==7||m==8||m==10)
        {
            if(brd+d>31) d2=(brd+d)-31, m2=m+1, y2=y;
            else if(brd+d==31) d2=31, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else if(m==12)
        {
            if(brd+d>31) d2=(brd+d)-31, m2=1, y2=y+1;
            else if(brd+d==31) d2=31, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
        else
        {
            if(brd+d>29) d2=(brd+d)-29, m2=m+1, y2=y;
            else if(brd+d==29) d2=29, m2=m, y2=y;
            else d2=brd+d, m2=m, y2=y;
        }
    }
    if(d2<=9&&m2<=9) cout<<"0"<<d2<<"."<<"0"<<m2<<"."<<y2<<endl;
    else if(d2<=9) cout<<"0"<<d2<<"."<<m2<<"."<<y2<<endl;
    else if(m2<=9) cout<<d2<<"."<<"0"<<m2<<"."<<y2<<endl;
    else cout<<d2<<"."<<m2<<"."<<y2<<endl;
        return 0;
}
