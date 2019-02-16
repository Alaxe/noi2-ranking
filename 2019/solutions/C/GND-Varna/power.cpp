#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,num[10000],i,num1=0,twomax=0,num2,twocheck=0,checker,checkmax=0,fl=0;
int nod(int a, int b)
{   int r;
if(a<b)swap(a,b);
    while(b)
    {
        r=a%b; a=b; b=r;
    }
    return a;
}
void k1()
{
num1=(num[0]*num[1])/nod(num[0],num[1]);
for(int j=2;j<n;j++)
{
num1=(num1*num[j])/nod(num1,num[j]);
}
}
int main()
{
cin>>n>>k;
for(i=0;i<n;i++)cin>>num[i];
k1();
if(k==1)cout<<num1<<endl;
else if(num1%2==0)
{
num2=num1;
while(num2%2==0)
{
num2/=2;
twomax++;
}
twomax*=k;
for(int i=0;i<n;i++)
{
checker=num[i];
while(checker%2==0)
{
checker/=2;
twocheck++;
}
if(twocheck>checkmax)checkmax=twocheck;
twocheck=0;
}
for(;;)
{
if(twomax-k>=checkmax){twomax-=k;num1/=2;}
else break;
}
}
cout<<num1<<endl;
return 0;
}
