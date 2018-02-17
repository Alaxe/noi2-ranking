#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
bool vv(int k,int v)
{
    bool b=true;
    do
    {
        int c=k%10;
        k=k/10;
        if(c==v)b=false;
    }while(k!=0);
    return b;
}
int main()
{
int n,l,a[3],br=0,ch;
cin>>n>>l;
for(int i=0;i<l;i++)
{
    cin>>a[i];
}
int t=1;
while(br!=n)
{
    if(l==3)
    {
        if(vv(t,a[0])==true&&vv(t,a[1])==true&&vv(t,a[2])==true)br++;
    }
    if(l==2)
    {
        if(vv(t,a[0])==true&&vv(t,a[1])==true)br++;
    }
    if(l==1)
    {
        if(vv(t,a[0])==true)br++;
    }
    ch=t;
    t++;
}
cout<<ch<<endl;
return 0;
}
