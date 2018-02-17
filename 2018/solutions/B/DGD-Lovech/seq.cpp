#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int n,m,a,b;
cin>>n>>m;
int br=0,i,sum,N;
for(i=1;i<pow(10,n);i++)
{   sum=0;
    while(i!=0)
    a=i%10;
    i=i/10;
    if(a>m)break;
    else{
    sum=sum+a;
    cout<<sum;
    if(sum==n)br++;
    }

}
cout<<br;
    return 0;
}
