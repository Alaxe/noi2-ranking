#include<iostream>

using namespace std;

long long a[1005],a1[1005],END[1005];
int b=1,b1;

int main()
{
    int n,k,j=1;
    cin>>n>>k;
    a[0]=1;
    for(int i=1;i<n;i++)
        a[i]=0;
    bool flag=false;
    for(int i=1;i<n;i++)
    {
        b=b*10;
        if(b<k && flag==false) continue;
        else if(b<k) {a1[j]=0;j++;continue;}
        flag=true;
        b1=b/k;
        a1[j]=b1;
        b1=b1*k;
        b=b-b1;
        j++;
    }

    a1[j-1]++;
    for(int i=j-1;i>0;i--)
    {
        if(a1[i]==10)
        {
            a1[i]=0;
            a1[i-1]++;
        }
        else break;
    }

    long long naum=0,i1;
    for(int k1=k,k2=10;k1>0;k1=k1/10,k2--)
    {
        i1=n-1+k2;
        for(int i=j-1;i>0;i--,i1--)
        {
            naum=a1[i]*k1/10;
            a[i1]=a1[i]*k1%10+naum;
            cout<<a[i1]<<" ";
        }
        cout<<endl;
        a[i1-1]=naum;
        naum=0;
        for(int i=n-1+k2;i>0;i--)
        {
            naum=(a[i]+END[i])/10;
            END[i]=END[i]+a[i]+naum;
            cout<<END[i]<<" ";
        }
        cout<<endl;
    }
    flag=false;
    for(int i=0;i<n+10;i++)
    {
        if(END[i]==0 && flag==false) continue;
        flag = true;
        cout<<END[i];
    }


    cout<<endl;
    return 0;
}
/*
15 1234567
*/
