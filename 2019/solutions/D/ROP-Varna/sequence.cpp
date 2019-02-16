#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int m[100];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,k,i,num=-1,br=0,p=0,a,j=0;
   cin>>n>>k;
    num=-1;p=0;
    for(i=1;;i++)
    {
        num+=2;
        p+=num;

        if(i==n)br++;
        if(i>n)br+=2;
        if(br==k){cout<<p-n+1<<endl;return 0;}
        if(br-1==k){cout<<p-(num-n)<<endl;return 0;}
    }

    return 0;
}

