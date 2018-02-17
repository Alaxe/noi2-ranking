#include<bits/stdc++.h>
using namespace std;
long long nach[100000];
long long otg[10000];
long long sum[10000];
int main(){
 long long n,k,a,b,stepa=0,stepb=0;
 cin>>n>>k>>a>>b;
 for(int i=0;i<n;i++){
    cin>>nach[i];
 }

 if(n==2){
if(nach[0]==nach[1]){
    for(int i=0;i<k;i++){
        cout<<nach[0]<<" ";
    }
    cout<<0<<"\n";
}else{
    long long br=0;
 for(int i=a;i<=b;i++){
    long long duljk=1,segi=0,ost=0,umnoj=1;
    br=0;
    for(int j=0;j<k;j++){
        duljk*=2;
        umnoj*=10;
    }
umnoj/=10;
    segi=i;
    while(duljk>1){

    if(duljk==0)break;

    if(segi<=duljk/2){
    duljk/=2;
    otg[i-a]+=nach[0]*umnoj;
    sum[i-a]+=nach[0];
    br++;
umnoj/=10;
    }else{
    duljk/=2;

    ost=segi%duljk;
    if(ost==0){
        ost=duljk;
    }
   segi=duljk+1-ost;
 otg[i-a]+=nach[1]*umnoj;
 sum[i-a]+=nach[1];
    br++;
    umnoj/=10;
    }
    }
 }

    for(int i=a;i<b;i++){
        sum[i-a]=abs(sum[i-a+1]-sum[i-a]);
    }
   sort(otg,otg+b-a+1);
   sort(sum,sum+b-a);
   cout<<otg[b-a]<<"\n"<<sum[b-a-1]<<"\n";

 }

}else{
for(int i=0;i<k;i++){
    cout<<nach[0];
}
cout<<abs(nach[0]-nach[1]);
}

return 0;
}
