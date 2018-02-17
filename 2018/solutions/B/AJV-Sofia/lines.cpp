#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,bla,bl=1,otg=0,otg2=0;
pair<int,int>dots[1024];
pair<double,pair<double,pair<int,int> > >pravi[1000001];
long long vz[1024];
bool dobaviii(int a,int b){
   // cout<<vz[a]<<",-"<<vz[b]<<" ";
   if(vz[a]!=bl){
    otg++;
   // cout<<"trik";
    vz[a]=bl;
   }
    if(vz[b]!=bl){
    otg++;
    vz[b]=bl;
   // cout<<"trak";
   }
return 0;
}
int x=0;
bool dobavi(int a,int b){
    pravi[x].second.second.first=a;
    pravi[x].second.second.second=b;
    if((dots[a].first-dots[b].first)==0){
            //cout<<"tuk";
        return 0;
    }
    if((dots[a].second-dots[b].second)==0){
        pravi[x].first=0;
        pravi[x].second.first=dots[a].second;
            }else{
    pravi[x].first=(double)(dots[a].second-dots[b].second)/(dots[a].first-dots[b].first);
    pravi[x].second.first=(double)(dots[a].second-(pravi[x].first*dots[a].first));
    }
    x++;
    return 0;
}
int main(){
    cout<<fixed<<setprecision(15);
cin>>n;
bla=((n*(n-1))/2);
for(int i=0;i<n;i++){
    cin>>dots[i].first>>dots[i].second;
}
for(int i=0;i<n;i++){
    for(int r=(i+1);r<n;r++){
        dobavi(i,r);
    }
}
sort(dots+0,dots+n);
otg=0;
for(long long i=0;i<n;i++){
    if(i>0 and dots[i].first==dots[i-1].first){
         //   cout<<"tak";
        otg++;
    }else{
        otg2=max(otg2,otg);
        otg=1;
    }
}
otg2=max(otg2,otg);
sort(pravi+0,pravi+x);
otg=0;
//sort(dots+0,dots+n);
for(int i=0;i<x;i++){
       // cout<<pravi[i].first<<" "<<pravi[i].second.first<<" "<<pravi[i].second.second.second<<" "<<pravi[i].second.second.first<<"\n";
if(i>0 and (pravi[i].first-pravi[i-1].first)<0.0000000001 and (pravi[i].first-pravi[i-1].first)>(-0.0000000001) and (pravi[i].second.first-pravi[i-1].second.first)<0.0000000001 and (pravi[i].second.first-pravi[i-1].second.first)>(-0.0000000001)){
       // cout<<"tuk"<<pravi[i].second.second.second;
dobaviii(pravi[i].second.second.second,pravi[i].second.second.first);
otg2=max(otg2,otg);
}else{
   // cout<<"tak";
    otg=0;
    bl++;
   // cout<<" "<<pravi[i].second.second.second<<" "<<pravi[i].second.second.first<<" ";
dobaviii(pravi[i].second.second.second,pravi[i].second.second.first);
otg2=max(otg2,otg);
}
}
otg2=max(otg2,otg);
cout<<otg2<<"\n";
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
