#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,a[10000],nok=1,num[10000]={0},numb[10000]={0},nun[10000]={0},nuz[10000]={0},c=0,m;
    cin>>n>>k;

    for(int i=0;i<n;i++)
       cin>>a[i];


    for(int i=0;i<n;i++)
    {
        for(int j=2;j<=a[i];j++)
        {
            while(a[i]%j==0)
            {
                numb[j]++;
                a[i]=a[i]/j;
            }
            if(numb[j]>num[j]) num[j]=numb[j];
            numb[j]=0;
        }
    }
    for(int i=0;i<=a[n-1]+4;i++)
      {if(num[i]>0) {if(num[i]%k>0) nun[i]=num[i]/k+1; else nun[i]=num[i]/k;
       nok=nok*nun[i]*i;}}
       cout<<nok<<endl;
    return 0;
}
