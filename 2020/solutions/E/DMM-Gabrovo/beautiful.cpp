# include <iostream>
using namespace std;

int main()
{
long long n,br=0,c,u,d,i;
cin>>n;
for(long long i=1;i<=n;i++)
{
d=i;
u=1;
c=0;
while(d>0)
{
 d=d/10;
 c=u+c;
 u=u*10;
}

if(i%c==0) br++;
}
cout<<br<<endl;

return 0;
}
