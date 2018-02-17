#include<iostream>
using namespace std;
int przapal(int s){
long long m,n,p=s,br,sbr;
bool d=true;
for(br=0;p>0;br++){
p=p/10;}
p=s;
long long k[br];
n=br-1;
sbr=br;
for(;br>0;br--){
k[br]=p%10;
p=p/10;
}
for(;d and br<sbr ;br++){

if(k[br]==k[br+n]){}else{d=false;}
n=n-2;
}
if(d==false){cout<<0;}else{cout<<1;}



return 0;}
int main(){
long long y,mn,mn2,pal,naipal=1,pal2;
cin>>y;
for(mn=0;mn<y;mn++){
for(mn2=0;mn2<y;mn2++){
pal2=mn*mn2;
pal=przapal(pal2);
if(pal==1 and pal2>=naipal){naipal=pal2;}
}
}
if(mn>mn2){swap(mn,mn2);}
cout<<mn<<" "<<mn2<<endl<<naipal<<endl;


return 0;
}
