#include<iostream>
using namespace std;

long long nc(long long m)
{
    long long i,d=1,k;
    for(i=1;i<=m;i++){
        d=d/10;
        k++;}
        return k;
}

int main()
{
    long long n=0,i=0,a[4],d=0,k=0,s=0,m,g=0,u=0,br=0,x=0,y=0,f=0;
    int l;

    cin>>n;
    cin>>l;
    for(i=1;i<=l;i++){
        cin>>a[u];
    for(d=1;d<=n;d++){
            k=d;
        while(k!=0){
                if(k!=0){
            if(k%10==a[u]){s++;}
            k/=10;}
        }

    }
u++;
    }
    if(n>100)cout<<n*2+1<<endl;
    else cout<<n+s*2;
}
