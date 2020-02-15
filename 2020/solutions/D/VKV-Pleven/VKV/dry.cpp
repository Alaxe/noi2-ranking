#include<iostream>
using namespace std;
unsigned long long n,v,u,s,i,m,o,br=1,p,a[100],f,l;
int main()
{
cin>>n>>u>>v;
s=u*v;
for(i=0;i<n;i++){
    cin>>a[i];
}
m=a[0];
l=a[n-1];
for(i=1;i<n;i++){
    if(a[i]>m){
        if(br==0) br++;
        o=o+s*m*br;
        m=a[i];
        p=i;
        br=1;
    }
    else br++;
    if(a[i]<=a[i-1]) f=1;
    else f=0;
}
if(m!=l && f==0){o=o+s*l*(br-1);}
if(f==1){
    for(i=p+1;i<n;i++){
        o=o+s*a[i];
    }
}
cout<<o;
return 0;
}
