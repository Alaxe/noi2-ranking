#include<iostream>
using namespace std;
int main ()
{
ios_base::sync_with_stdio(0);
int a[100002],n,u,v,s=0,x=0,i=0,y=0;
cin>>n>>u>>v;
for(int j=1;j<=n;j++)
{
    cin>>a[j];
}
while(i<=n)
{

    i++;
    if(x!=0)y++;
    if(x>0 && a[i+1]<=a[i]){x=0;y=0;s=s+(u*v*a[i+1]);continue;}
    if(a[i+1]>a[i] && x>0 && a[i+1]<=x){s=s+(a[i+1]*u*(y+1)*v);}
    if(a[i+1]>a[i] && x>0 && a[i+1]>x){s=s+(x*u*(y+1)*v);}
    if(a[i]<=a[i+1] && x==0){s=s+(u*v*a[i]);}
    if(a[i]>a[i+1] && y==0)
    {
        x=a[i];
    }
}
cout<<s<<endl;

    return 0;
}

