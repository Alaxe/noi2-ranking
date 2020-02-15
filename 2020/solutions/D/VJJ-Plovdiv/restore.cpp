#include<iostream>
using namespace std;
int main()
{ int n;
cin>>n;
bool r=0;
int m[n],m1[n],p=0;
for (int i=0;i<n;i++)
{
    cin>>m[i];
}
for (int i=0;i<n-1;i++)
{
    if (m[i]!=0) m1[i]=n-m[i]-i;
    else {m1[i]=n-p;p++;}
}
for (int i=1;i<n;i++)
{   r=0;
    for (int ii=0;ii<n;ii++)
    {
        if (i==m1[ii]) r=1;
    }
    if (r==0) {m1[n-1]=i;cout<<i<<endl;break;}
}
for (int i=0;i<n;i++) cout<<m1[i]<<" ";
cout<<endl;
return 0;
}
