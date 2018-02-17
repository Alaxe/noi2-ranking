#include<iostream>
using namespace std;

long long nc(long long m)
{
    long long i,d=1;
    for(i=1;i<=m;i++){
        d=d*10;}
        return d/10;
}

long long ng(long long h)
{
     long long i,d=1,br=0,k,l=9,c=0;
    for(i=1;i<h;i++){
            d*=10;
            br++;
      }
      for(k=1;k<=br;k++){

            l*=10;
            l+=9;

      }

        return l;
}

int main()
{
long long n,k,i,c,m,br=0;
cin>>n>>k;
c=nc(n);
m=ng(n);

for(i=c;i<=m;i++){

    if(i%k==0){br++;cout<<i<<endl;break;}
}

if(br==0)cout<<"NO"<<endl;
}
