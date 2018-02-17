#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int chmax(int n)
{
    int chc=1;
    while(n!=1)
    {
        chc=chc*99;
        n--;
    }
    return chc;
}
int chmin(int n)
{
    int chc2=1;
    while(n!=1)
    {
        chc2=chc2*10;
        n--;
    }
    return chc2;
}
int brc(int a)
{
    int br=0;
    do
    {
        a=a/10;
        br++;
    }while(a!=0);
    return br;
}

int main()
{
    long long int n,k;
    cin>>n>>k;
    long long int maxch=chmax(n);
    long long int minch=chmin(n);
   long long  int min=10000000;
   for(int i=minch;i<=maxch;i++)
{
    if(i%k==0&&i<min)min=i;
}
if(min==10000000)
{
    cout<<"NO"<<endl;
    return 0;
}
cout<<min<<endl;
return 0;
}