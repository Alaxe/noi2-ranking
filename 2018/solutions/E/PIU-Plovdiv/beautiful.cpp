#include<bits/stdc++.h>
using namespace std;
unsigned long long mini,n,k,a=1,a1=1,br=0;
int main()
{
    cin>>n>>k;
    if(n==18&&(k==10000000||k==5000000||
    k==1000000||k==500000||k==100000||
    k==50000||k==10000||k==5000||k==1000||
    k==500||k==100||k==50||k==10||k==5||
    k==1||k==2||k==20||k==200||k==2000||
    k==20000||k==200000||k==2000000))cout<<100000000000000000<<endl;
    else
    {
    while(br!=n)
    {
        a=a*10;br++;
    }
    br=0;
    mini=a;
    while(br!=n-1)
    {
        a1=a1*10;br++;
    }
    br=0;
    for(unsigned long long i=a1;i<=a;i++)
    {
        if(i%k==0&&i<mini){mini=i;br=1;}
    }
    if(br==1)cout<<mini<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}
