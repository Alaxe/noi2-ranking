#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n,k,a,deliteli[43]={0},gcd,otg,p=1;
    bool tf=true;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        for(int j=2;j<=a;j++)
        {
            while(a%j==0)
            {
                a=a/j;
                deliteli[j]++;
            }
        }
    }
    for(int i=1;i<=deliteli[2];i++)
    {
        for(int j=2;j<=43;j++)
        {
            if(deliteli[j]%i!=0){tf=false;break;}
        }
        if(tf==true)gcd=i;
        tf=true;
    }
    for(int i=2;i<43;i++)
    {
        deliteli[i]=deliteli[i]/gcd;
        for(int j=0;j<deliteli[i];j++)
        {
            p=p*i;
        }
    }
    cout<<p<<endl;

    return 0;
}
