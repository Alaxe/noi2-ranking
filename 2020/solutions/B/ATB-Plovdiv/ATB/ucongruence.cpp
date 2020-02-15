#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
ll j,nn,n,u,aa[1100000],i,f[70],br,ff[70];
unsigned ll comb(ll p,ll q)
{
    ll p1=1;
    unsigned ll ot=1;
    for(ll ii=p;ii>p-q;ii--){
        ot*=ii;
        if(ot%p1==0&&p1<=q){ot/=p1;p1++;}
    }
    return ot;
}
vector<ll>a,b;
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>nn>>u;
for(i=0;i<nn;i++)cin>>aa[i];
for(i=0;i<nn;i++)f[aa[i]]=1;
for(i=1;i<=u;i++)if(f[i]==1)a.push_back(i);
n=a.size();
br=comb(u,n);
br=(br+1)/2;
ll last=0;
for(i=0;i<n;i++)
{ll tec=0;
    for(j=last+1;j<=u;j++)
    {if(comb(u-j,n-i-1)+tec<br)tec+=comb(u-j,n-i-1);
    else{br-=tec;last=j;b.push_back(last);break;}
    }
}
ll e=0;
for(i=1;i<=u;i++)
{
    if(f[i]==1){ff[i]=b[e];e++;}
}
for(i=0;i<nn-1;i++)cout<<ff[aa[i]]<<" ";
cout<<ff[aa[nn-1]]<<endl;
return 0;
}
