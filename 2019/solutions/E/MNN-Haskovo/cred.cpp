#include <iostream>
using namespace std;
int main ()
{
long long n,m,x,c,sum=0,br=1;
cin>>n>>m;
for(int i=n;i<=m;i=sum)
{
  sum=0;
  x=i;
  while(x)
  {
      c=x%10;
      sum=sum+c;
      x=x/10;
  }
  sum=sum+i;
  br++;
}

if(sum>m)cout<<br-1<<endl;
else
cout<<br<<endl;


}

