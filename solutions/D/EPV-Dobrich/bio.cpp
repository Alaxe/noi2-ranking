#include<iostream>
using namespace std;
struct date
{
    int d;
    int m;
    char ch;
};
int main()
{
    bool k=true;
    int p, raz, h=0, d;
    date a[4];
    int brd[4];
    for(p=0; p<4;p++)
    {
        cin>>a[p].d>>a[p].ch>>a[p].m;
    }
    for(p=0; p<4;p++)
    {
        brd[p]=a[p].d;
        a[p].m--;
        if(a[p].m<2) {brd[p]=brd[p]+31*a[p].m;  }
        else
        {
            if(a[p].m<7) brd[p]=brd[p]+(a[p].m/2)*31+28+(a[p].m-a[p].m/2-1)*30;
            else{brd[p]=brd[p]+2*30+28+4*31; a[p].m=a[p].m-7; brd[p]=brd[p]+(a[p].m/2)*31+(a[p].m-a[p].m/2)*30; }
        }
    }
    if(brd[1]!=brd[2])
    {
        raz=brd[1]-brd[2];
        do
        {
            h++;
            if((28*h+raz)%23==0) k=false;
        }
        while (k);
        //cout<<h<<" "<<brd<<endl;
        brd[2]=brd[2]+28*h;
        brd[1]=brd[2];
    }
    if(brd[2]!=brd[3])
    {
        raz=brd[2]-brd[3];
        do
        {
            h++;
            if((35*h+raz)%644==0) k=false;
        }
        while (k);
        brd[3]=brd[3]+35*h;
        brd[2]=brd[3];
        brd[1]=brd[3];

    }
    d=brd[4]-brd[3];
    if(d==0) d=21252;
    if(d>21252) d=d-21252;
    cout<<d<<endl;
}
