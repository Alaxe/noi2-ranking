#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int a,a1,da=0;
int b,b1,db=0;
int c,c1,dc=0;
int t,t1,dt=0;
char c2;
cin>>a>>c2>>a1>>b>>c2>>b1>>c>>c2>>c1>>t>>c2>>t1;
for(int i=1;i<max(a1,max(b1,max(c1,t1)));i++)
{
    if(i==1 ||i==3 ||i==5 ||i==7 ||i==8 ||i==10 ||i==12){if(i<a1)da+=31;;if(i<b1)db+=31;;if(i<c1)dc+=31;if(i<t1)dt+=31;}
    else if(i==4 ||i==6 ||i==9 ||i==11 ){if(i<a1)da+=30;;if(i<b1)db+=30;;if(i<c1)dc+=30;if(i<t1)dt+=30;}
    else{if(i<a1)da+=28;;if(i<b1)db+=28;;if(i<c1)dc+=28;if(i<t1)dt+=28;}
}
da+=a;
db+=b;
dc+=c;
dt+=t;
int y;
while(1)
{   if(da==db && da==dc)break;
y=min(da,min(dc,db));
    if(y==da)da+=23;
    else if(y==db)db+=28;
    else if(y==dc)dc+=33;
}
if(da-dt>0)cout<<da-dt<<endl;
else cout<<21252+(da-dt)<<endl;;
return 0;
}
/*
1/1 1/1 1/1 1/1
23/7 29/10 23/7 10/2
*/
