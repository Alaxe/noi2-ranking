#include<bits/stdc++.h>
using namespace std;
pair<long long,long long >tochki[1002];
pair<long long,long long >tochki2[1002];
pair<long long,long long>tochki3[1002];
pair<double,double>ura[1000005];
double eps=0.00001;

long long S(long long a,long long b,long long c,long long d){
long long pr=0;
pr=(b+d)*(c-a);
return pr;
}

int main(){
   ios_base::sync_with_stdio(false);
cin.tie(0);
long long n,a=0,b=0,otg=0,seg=0,sum=0,br=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a>>b;
    tochki[i]=make_pair(a,b);
    tochki2[i]=make_pair(a,b);
    tochki3[i]=make_pair(b,a);
}
sort(tochki2,tochki2+n);
sort(tochki3,tochki3+n);
seg=1;
otg=0;
for(int i=1;i<n;i++){
if(tochki2[i].first==tochki2[i-1].first){
    seg++;
}else{
otg=max(otg,seg);
seg=1;
}
}
otg=max(otg,seg);
seg=1;
for(int i=1;i<n;i++){
if(tochki3[i].first==tochki3[i-1].first){
    seg++;
}else{
otg=max(otg,seg);
seg=1;
}
}
otg=max(otg,seg);
seg=1;

for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
/*seg=2;
        for(int h=j+1;h<n;h++){
                  sum=0;
            sum+=S(tochki[i].first,tochki[i].second,tochki[j].first,tochki[j].second);
            sum+=S(tochki[j].first,tochki[j].second,tochki[h].first,tochki[h].second);
            sum+=S(tochki[h].first,tochki[h].second,tochki[i].first,tochki[i].second);
            if(sum==0){
                seg++;
            }
           // cout<<i<<" "<<j<<" "<<h<<" "<<sum<<"\n";
        }
        otg=max(otg,seg);
        */
        if(tochki[i].first!=tochki[j].first and tochki[i].second!=tochki[j].second){
                double c=0,d=0;
        c=(double)tochki[i].second-tochki[j].second;
        c/=(double)tochki[i].first-tochki[j].first;
        d=(double)tochki[i].second-c*tochki[i].first;
        ura[br]=make_pair(c,d);
        br++;
        }
    }
}

sort(ura,ura+br);
seg=1;

for(int i=1;i<br;i++){
    if(max(ura[i].first,ura[i-1].first)-min(ura[i].first,ura[i-1].first)<=eps){
      if(max(ura[i].second,ura[i-1].second)-min(ura[i].second,ura[i-1].second)<=eps){
        seg++;
    }else{
        seg*=2;
    a=sqrt(seg);
    while(a*(a-1)<seg){
        a++;
    }
    //cout<<seg<<" "<<ura[i-1].first<<" "<<ura[i-1].second<<"\n";
    otg=max(otg,a);
    seg=1;
    }
    }else{
       seg*=2;
    a=sqrt(seg);
    while(a*(a-1)<seg){
        a++;
    }
   //  cout<<seg<<" "<<ura[i-1].first<<" "<<ura[i-1].second<<"\n";
    otg=max(otg,a);
    seg=1;
    }
}
       seg*=2;
    a=sqrt(seg);
    while(a*(a-1)<seg){
        a++;
    }
    //cout<<seg<<" "<<ura[n-1].first<<" "<<ura[n-1].second<<"\n";
    otg=max(otg,a);
    seg=1;

cout<<otg<<"\n";
return 0;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
