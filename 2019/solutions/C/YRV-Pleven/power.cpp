#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
long long nok2=1,n,k,fl[100001],a1,b1,c,i,k2,a[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41},br,ans=1;
void nok(long long a,long long &b){
    a1=a;
    b1=b;
    while(a1*b1!=0){
        c=b1;
        b1=a1%b1;
        a1=c;
    }
    b=a*b/(a1+b1);
    //cout<<a1+b1<<" "<<b<<endl;
}
int main(){
//cin>>a>>b>>c>>d;
cin>>n>>k;
for(i=1;i<=n;i++){
    scanf("%lld",&k2);
    if(fl[k2]==0){
        fl[k2]=1;
        nok(k2,nok2);
    }
}
//cout<<nok2<<endl;
for(i=1;i<=13;i++){
    br=0;
    //cout<<a[i]<<endl;
    while(nok2%a[i]==0){
        br++;
        if(br%k==1)ans*=a[i];
        nok2/=a[i];
    }

}
cout<<ans<<endl;
return 0;
}
