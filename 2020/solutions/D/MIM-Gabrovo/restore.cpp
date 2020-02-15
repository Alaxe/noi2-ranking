#include<iostream>
using namespace std;
int main ()
{
ios_base::sync_with_stdio(0);
int n,a[100002],b[100002]={0},x=0,y=0,u[100002]={0},f=1,br=0,z;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}
x=n-a[1];
u[x]=1;
b[1]=x;
for(int i=2;i<=n;i++)
{
    y=n-a[i];
    z=0;
    br=0;
    f=1;
    if(a[i]>a[i+1])f=2;
    if(x>=y)
    {
        y--;
        if(u[y]==1)
        {while(1)
        {
            y--;
            if(y==0){y=z;break;}
            if(u[y]==0 && y!=0){br++;z=y;}
            if(u[y]==0 && f==1)break;
            if(br==a[i]+1 && f==2)break;
        }
        }
    }
    b[i]=y;
    u[y]=1;
    x=max(x,y);
}
for(int i=1;i<=n;i++)
{
    if(i==n){cout<<b[i]<<endl;return 0;}
    cout<<b[i]<<" ";
}
    return 0;
}

