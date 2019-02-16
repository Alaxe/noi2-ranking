#include <iostream>


using namespace std;

int d(long long n)
{
n=n+n/100000+n%100000/10000+n%10000/1000+n%1000/100+n%100/10+n%10;
return n;
}

int main()
{
long long n,m;
cin>>n>>m;
int a=0;
while(n<=m)
{
    n=d(n);
    a++;
}
cout<<a<<endl;
    return 0;
}

