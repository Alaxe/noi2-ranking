#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=1,n,k,i=1,s=0;
    string S="1";
    cin>>n>>k;
    while(a<k){a*=10;i++;}
    s=a%k;
    for(int j=i;j<n;j++)
    {
        s*=10;
        if(s>=k)s%=k;

    }
    int br=0;
    s=k-s;///cout<<s<<endl;
    int sdub=s;
    while(sdub)
    {
        sdub/=10;
        br++;
    }
    ///cout<<br<<endl;
    for(int j=1;j<n-br;j++)
    {
        S=S+'0';
    }
    ///cout<<S<<s<<endl;
    string S2="";
    for(int j=0;j<br;j++)
    {
        S2=S2+(char)((s%10)+'0');
        s/=10;
    }
    ///cout<<S2<<endl;
    reverse(S2.begin(),S2.end());
    S=S+S2;
    string S3="1";
    if(k==10 || k==100 || k==1000 || k==10000 || k==100000 || k==1000000 || k==10000000)
    {
        for(int j=1;j<n;j++)
        {
            S3=S3+'0';
        }
        cout<<S3<<endl;
    }
    else cout<<S<<endl;
}
/**
15 1234567
*/
