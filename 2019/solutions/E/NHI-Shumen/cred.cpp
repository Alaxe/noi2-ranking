#include<iostream>
#include <algorithm>
#include <cmath>


using namespace std;
int d(int n)
{
    if(n<10)n=n+n%10;
    if(n>=10&&n<100)
    {
        int des=n/10;
        int ed=n/1%10;
        n=n+des+ed;
    }
    if(n>=100&&n<=999)
    {
        int st=n/100;
        int des=n/10%10;
        int ed=n%10;
        int sum=st+des+ed;
        n=n+st+des+ed;
    }
    if(n==1000)
    {
        int st=n/100%10;
        int des=n/10%10;
        int ed=n/1%10;
        int sum=st+des+ed;
        n=n+1+sum;
    }
    return n;
}
int main()
{
    int n,m,br=0;
    cin>>n>>m;
    if(n<=m)br++;
    for(int i=n;i<m;i++)
    {
        if(d(i)<m)
        {
            i=d(i);
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
