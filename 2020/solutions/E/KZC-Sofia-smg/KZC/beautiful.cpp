#include<iostream>
using namespace std;
int main()
{
long long N,br=0,a,b,c=0,d=0,m;
cin>>N;
for(long long i=1;i<=N;i++)
{
if(i<10)
{
    br++;
}
m=i;
if(i>9)
{
while(i!=0)
{
a=i%10;
i=i/10;
if(i>0)
{
b=i%10;
}
if(i>0)
{
i=i/10;
}
if(a==b)
{
c++;
}
d++;
}
if(c==d)
{
br++;
}
i=m;
c=0;
d=0;
}
}
cout<<br<<endl;
return 0;
}
