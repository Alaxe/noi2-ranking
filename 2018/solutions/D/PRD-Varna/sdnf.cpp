#include<bits/stdc++.h>
using namespace std;
long long int mult(long long int n, long long int m)
{
    long long int sum[10001], p,a,b, br1=0,br=0, br2=0, sum1;
    a=n;
    b=m;
    while(a)
    {
        a/=10;
        br1++;
    }
    while(b)
    {
        b/=10;
        br++;
    }
    if(br1<br){
        for(int i=0;i<br1;i++)
        {
            p=n%10;
            n/=10;
            sum[i]=m*p;
            br2++;
        }
    }
    else if(br1>br){
        for(int i=0;i<br;i++)
        {
            p=m%10;
            m/=10;
            sum[i]=n*p;
            br2++;
        }
    }
    for(int i=0;i<br2;i++)
    {
        if(i==0)sum1+=sum[i];
        else sum1+=sum[i]*(i*10);
    }
    return sum1;
}

long long int fact(long long int n)
{
    long long int f=1;
    for(long long int i=1;i<=n;i++)
        f=mult(f,i);

    return f;
}

int main()
{
    long long int n, p=0, sum=0;
    cin>>n;
    cout<<fact(n)<<endl;
}
