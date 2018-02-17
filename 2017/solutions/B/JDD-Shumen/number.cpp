#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long int max(long long int a, long long int b)
{
    return a>b ? a : b;
}
long long int n, m;
long long int binary1()
{
    long long int left=1;
    long long int right=10000000000;
    long long int mid;
    while((right-left)>1)
    {
        mid=(left+right)/2;
        //cout<<mid<<endl;
        if(mid*(mid+1)<n)
            left=mid;
        else
            right=mid-1;
    }
    return right;
}
long long int binary2()
{
    long long int left=1;
    long long int right=10000000000;
    long long int mid;
    while((right-left)>1)
    {
        mid=(left+right)/2;
        //cout<<mid<<endl;
        if(mid*(mid+1)>m)
            right=mid-1;
        else
            left=mid;
    }
    return left;
}
int main()
{
    scanf("%lld %lld", &n, &m);
    /*long long int sqrt1=sqrt(n);
    long long int sqrt2=sqrt(m);
    if(sqrt1*(sqrt1+1)<n)
        sqrt1++;
    if(sqrt2*(sqrt2+1)>m)
        sqrt2--;
    //cerr<<sqrt1<<' '<<sqrt2<<endl;
    //cout<<max(sqrt2-sqrt1+1, 0)<<endl;*/
    /*cout<<binary1()<<endl;
    cout<<binary2()<<endl;*/
    cout<<binary2()-binary1()+1<<endl;
return 0;
}
