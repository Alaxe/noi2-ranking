#include<iostream>
using namespace std;
int main (){
long long N,L,k,m=0,cs,v=0,ch,sh=1,kloni,y;
cin>>N>>L;
long long l[L];
for(int a=0;a<L;a++){
cin>>l[a];
}
for(int d=0;d<N;v=0,sh++){
kloni=sh;
while(kloni!=0){
cs=kloni%10;
kloni=kloni/10;
for(int h=0;h<L;h++){
if(cs==l[h]){
v=v+1;
}
}
}
if(v==0){
d=d+1;
}
}
for(int z=0;z<L;z++){
if(l[z]!=1){
y++;
}
}
cout<<sh-1;
return 0;
}
