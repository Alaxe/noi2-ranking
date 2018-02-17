#include<bits/stdc++.h>
using namespace std;
/*long long n,i=1,br=1,dig=1,dig2=1;
unsigned diff[10000000],num[10000000];
long long ico(int g)
{
if(g==1)return 10;
return 10*ico(g-1);
}
long long ch(int a)
{
int r=a;
if(br==0 && r>ico(i)){diff[i]=r/ico(i);br=1;}
if(a==1)return 1;
return a*ch(a-1);
}

void del(int s)
{
int dig2=dig;
int z=1;
for(z=1;z<=s;z++)dig2/=10;
}
int main(){

cin>>n;
for(i=1;i<=n;i++){
for(int j=1;j<=n;j++)
{
dig*=j;
if(del(br)>0){br++;diff[br]=del(br);}
if(dig>)
}
num[i]=
}
cout<<ch(n)<<endl;


return 0;
}*/

long long n;
long long  sbor=0;
unsigned fact(int n)
{
if(n==1 || n==0)return 1;
return n*fact(n-1);
}
long long sum()
{
unsigned fac=fact(n);
while(fac)
{
sbor+=fac%10;
fac/=10;
}
return sbor;
}
int main()
{
cin>>n;
cout<<sum()<<endl;
return 0;
}
