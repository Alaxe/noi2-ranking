#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
using namespace std;
long long fl[61],n,u,b[1000001],c[61],br2,br,a[61],ans[61],ch,nod,poz,tl,tr,td,pr,tbr,nom,l,r,sum;
vector <long long> v1,v2;
long long comb(long long el,long long kl){
    ch=1;
    int i,j;
    v1.clear();
    v2.clear();
    for(i=el;i>=el-kl+1;i--)v1.push_back(i);
    //for(i=0;i<kl;i++)cout<<v1[i]<<" "; cout<<endl;
    for(i=kl;i>=1;i--)v2.push_back(i);
    //for(i=0;i<kl;i++)cout<<v2[i]<<" "; cout<<endl;
    for(i=0;i<kl;i++){
        for(j=0;j<kl;j++){
            if(v2[i]==1)break;
            nod=__gcd(v2[i],v1[j]);
            v1[j]/=nod;
            v2[i]/=nod;
        }
    }
    for(i=0;i<kl;i++)ch*=v1[i];
    //for(i=0;i<kl;i++)if(v1[i]!=0)cout<<v1[i]<<" "; cout<<endl;
    //cout<<ch<<endl;
    return ch;
}
pair <long long,long long> p;

void fff(){
    int i;
    tbr=1;
    pr=0;
    for(i=1;i<=br+1;i++){
        if(ans[i]==0){
            td++;
        }
        else{
            if(td!=0)tbr*=comb(ans[i]-ans[pr]-1,td);
            //cout<<i<<" "<<td<<" "<<tbr<<endl;
            td=0;
            pr=i;
        }
    }
   //cout<<tbr<<endl;
}
int main(){
int i,j;
cin>>n>>u;
for(i=1;i<=n;i++){
    scanf("%lld",&b[i]);
    fl[b[i]]++;
}
for(i=1;i<=u;i++){
    if(fl[i]!=0)c[i]=++br2;
    fl[i]=0;
}
for(i=1;i<=n;i++){
    fl[b[i]]++;
    if(fl[b[i]]==1)a[++br]=c[b[i]];
}
//for(i=1;i<=br;i++)cout<<a[i]<<" "; cout<<endl;
ans[br+1]=u+1;
poz=(comb(u,br)+1)/2;
//cout<<poz<<endl;
for(i=1;i<=br;i++){
    // shte fiksirame tekushtoto a[i] chislo
    //namiram min i maks stoinoist na tekushtoto chislo
    nom=a[i];
    l=i; r=u-(br-nom);
    p.first=p.second=0;
    for(j=1;j<nom;j++){
        if(ans[j]!=0){p.first=j; p.second=ans[j];}
        //opredelqm l;
    }
    if(p.first!=0)l=nom-p.first+p.second;

    p.first=p.second=0;
    for(j=br;j>nom;j--){
        if(ans[j]!=0){p.first=j; p.second=ans[j];}
            //opredelqm r
    }
    if(p.first!=0)r=p.second-(p.first-nom);
    //cout<<"!!! "<<nom<<" "<<sum<<" "<<l<<" "<<r<<endl;
    for(j=l;j<=r;j++){
        ans[nom]=j;
        fff();
        if(sum+tbr>=poz){
            ans[nom]=j;
            break;
        }
        else sum+=tbr;
    }
}
for(i=1;i<=n;i++){
    //cout<<c[b[i]]<<" "<<ans[c[b[i]]]<<"  ";
    printf("%lld ",ans[c[b[i]]]);
}
cout<<endl;
return 0;
}
/*

*/
