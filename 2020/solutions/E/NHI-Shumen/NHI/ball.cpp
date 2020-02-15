#include<iostream>
using namespace std;
int main()
{int n,x;
 cin>>n>>x;
 int nu=0;
 int ed=0;
 int dv=0;
 int po=0;
 if(x==0)
 {
     nu=1;
     for(int i=0;i<=n;i++)
 {
    if(i%2==0)
    {
         po=nu;
         nu=dv;
         dv=po;
    }
     else
    {
        po=ed;
        ed=dv;
        dv=po;
    }
 }
 }
 if(x==1)
 {
     ed=1;
     for(int i=0;i<=n;i++)
 {
    if(i%2==0)
    {
         po=nu;
         nu=dv;
         dv=po;
    }
     else
    {
        po=ed;
        ed=dv;
        dv=po;
    }
 }
 }
 if(x==2)
 {
     dv=1;
     for(int i=0;i<=n;i++)
 {
    if(i%2==0)
    {
         po=nu;
         nu=dv;
         dv=po;
    }
     else
    {
        po=ed;
        ed=dv;
        dv=po;
    }
 }
 }
 if(nu==1)
 {
     cout<<"2"<<endl;
 }
 if(ed==1)
 {
     cout<<"1"<<endl;
 }
 if(dv==1)
 {
     cout<<"0"<<endl;
 }
    return 0;
}
