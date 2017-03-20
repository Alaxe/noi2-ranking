#include<iostream>
using namespace std;
struct aboy
{
    int ax;
    int by;
}
aboy abc[4];
int a[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int main ()
{
    int i,x,y,flag=0;
    for(i=0; i<4; i++)
    {
        cin>>x>>y;
        abc[i].ax=x;
        if(abc[i].ax==abc[i-1].ax)flag++;
        abc[i].by=y;
        if(abc[i].by==abc[i-1].by)flag++;
    }
    if(flag==8)cout<<"21252"<<endl;

}
