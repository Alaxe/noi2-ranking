#include<iostream>
using namespace std;  
long long int n,j,i,a[1000],sum;
bool bin[1000],bru[1000000],brd[1000000];
void check()
{
    long long sum=0,fl=0;
    for(i=0;i<n;i++)
    {
        if(bin[i]==true) fl=1;
        sum+=bin[i]*a[i];
    }
    if(fl==1)
    if(sum<0) {sum*=-1;brd[sum]=true;}
    else bru[sum]=true;
}
void genbin(int i,bool m)
{
    bin[i]=m;
    if(i==n-1){check();return;}
    genbin(i+1,0);
    genbin(i+1,1);
}
int main()
{
cin>>n;
for(i=0;i<n;i++)
{
    cin>>a[i];
}
genbin(0,0);
genbin(0,1);
sum=0;
for(i=0;i<=1000000;i++)sum+=bru[i];
for(i=1;i<=1000000;i++)sum+=brd[i];
cout<<sum<<endl;
return 0;
}
/* 5
1 -2 0 7 7 */