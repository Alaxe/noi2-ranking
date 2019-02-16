#include<iostream>
#include<stdio.h>
using namespace std;
long long i,j,p,n,k,x,q,b[15] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41},a[15],br,s;
long long d,f;
int main()
{
    cin>>n>>k;
    d=13;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&p);
        for(j=1;j<=d;j++)
        {
            //cout<<b[j]<<" ";
            br=0;
            while(p%b[j]==0)
            {
                p/=b[j];
                br++;
            }
            if(br>a[j])a[j]=br;
        }
    }
    s=1;
    for(i=1;i<=d;i++)
    {
        if(a[i]%k==0)p=a[i]/k;
        else p=a[i]/k+1;
        f=1;
        x=b[i];
        while(p!=0)
        {
            //cout<<x<<" xi "<<i<<endl;
            if(p%2!=0){f=f*x;}
            x=x*x;
            p/=2;
        }
        //cout<<f<<endl;
        s*=f;
    }
    cout<<s;
    return 0;
}
/*
42 999
1 2 3  4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42

4 3
3 4 5 6


5 3
3 4 5 6 7

5 6
3 4 5 6 8

3 12
13 15 14

4 3
128 3 5 6
*/
