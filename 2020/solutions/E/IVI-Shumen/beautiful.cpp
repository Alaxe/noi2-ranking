#include<iostream>
#include<cmath>
using namespace std;

bool beautiful(long long int n)
{
    if(n>=1&&n<=9) return true;
    long long int c=n%10;
    n/=10;
    long long int br=1;
    long long int h=1;
    do
    {
        if(c==n%10) br++;
        h++;
        n/=10;
    }while(n!=0);
    return br==h;
}
int main()
{
long long int n;
cin>>n;
long long int cnt=0;
for(int i=1;i<=n;i++)
{
    if(beautiful(i)) {cnt++;}
}
cout<<cnt<<endl;
return 0;
}
