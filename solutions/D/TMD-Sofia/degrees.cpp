#include<iostream>
using namespace std;
int main(){
long long a,ac,br=0,i,b=0,st,k;
cin>>a;
ac=a;
while(ac!=0){
ac=ac/10;
br++;
}
if(br==1){cout<<1;}else{
if(br==2){cout<<2;}else{
if(br==3){cout<<3;}else{
b=3;
st=3;
for(i=1;true;i++){
k=3*i+3;
if(i%3==1 or i%3==2){
if(b+k>=br){break;}else{b=b+k;st=st+3;}
}
if(i%3==0){
if(b+k+i+1>=br){break;}else{b=b+k+i+1;st=st+4;}
}
}
st=st+(br-b)/(i+1);
cout<<st;
}
}
}
cout<<endl;
return 0;
}
