#include<bits/stdc++.h>
using namespace std;
unsigned n,k,br=0,nok,mins=1,times,diff;

void zero()
{
    unsigned r=n,r2=k;
while(r%10==0 && r2%10==0){

r/=10;
r2/=10;
br++;
}
nok=n*k;
for(int i=1;i<=br;i++)nok/=10;
}


void del()
{
while(nok)
{
if(nok%2==0 && (nok/2)%n==0 && (nok/2)%k==0)nok/=2;
else break;
}
while(nok)
{
if(nok%3==0 && (nok/3)%n==0 && (nok/3)%k==0)nok/=3;
else break;
}
while(nok)
{
if(nok%5==0 && (nok/5)%n==0 && (nok/5)%k==0)nok/=5;
else break;
}
}


void minsize()
{
for(int m=1;m<n;m++)mins*=10;
}




unsigned length()
{
    unsigned z=nok,nok2;
while(z)
{
z/=10;
br++;
}
if(br==n)return nok;
diff=n-br;
for(int s=1;s<=diff;s++)nok*=10;
diff=nok-mins;
nok2=nok;
for(int i=1;i<=br;i++)nok/=10;
times=(diff/nok);
return nok2-times*nok;
}


int main()
{
cin>>n>>k;
zero();
del();
minsize();
cout<<length()<<endl;
return 0;
}
