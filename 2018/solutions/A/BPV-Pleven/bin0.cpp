#include <iostream>

using namespace std;

string binnary(int a)
{
    string s="";
    while(a>0)
    {
        if(a%2==0)s+='0';
        else s+='1';
        a/=2;
    }
    return s;
}

int main()
{
    long long s,t;
    int z,br1=0,br=0;
    string num;
    cin>>s>>t>>z;

    int a[53][53];
    int k=0;
    a[0][0]=1;a1[0][1]=1;
    for(int i=2;i<53;i++)
        a[0][i] = a1[0][i-1] + i;

    for(int j=1;j<53;j++)
    {
        k++;
        for(int i=0;i<k;i++)
            a[j][i]=0;
        a[j][k]=1;a[j][k+1]=1;
        for(int i=k+2;i<50;i++)
            a[j][i] = a[j][i-1] + a[j-1][i-1];
    }

    if(z>53){cout<<0<<endl; return 0;}

    for(int i=s;i<=t;i++)
    {
        num = binnary(i);
        br1=0;
        for(int j=0;j<num.length();j++)
            if(num[j]=='0')br1++;
        if(br1==z)br++;
    }
    cout<<br<<endl;

    return 0;
}
