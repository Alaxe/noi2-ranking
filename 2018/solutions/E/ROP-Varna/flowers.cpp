#include<iostream>
using namespace std;
int main()
{
long long n,a,q,i,s=0,br=0,k;
cin>>n;
long long m[100000];

for(i=0;i<n;i++){
    cin>>m[i];
    if(m[i]>s)s=m[i];
    }
i=-1;
for(k=1;k<=n;k++)
{i++;
    br+=s-m[i];
}
cin>>q;
cout<<br*q;
}
