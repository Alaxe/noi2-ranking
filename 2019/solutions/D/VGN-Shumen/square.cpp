#include<iostream>
using namespace std;
long long int a[10000];
long long int nod(long long int a,long long int b)
{
    while(b!=0)
    {
        long long int p=a%b;
        a=b;
        b=p;
    }
    return a;
}
long long int nok(long long int a,long long int b)
{
    long long int p=a*b;
    long long int r=p/nod(a,b);
    return r;
}
int main()
{
long long int n;
cin>>n;
long long int r=1,minn=45;
for(long long int i=0;i<n;i++)
{
    cin>>a[i];
    if(r%a[i]!=0)r=nok(r,a[i]);
    if(a[i]<minn)minn=a[i];
}
while(minn*minn%r!=0)minn++;
cout<<minn<<endl;
return 0;
}
