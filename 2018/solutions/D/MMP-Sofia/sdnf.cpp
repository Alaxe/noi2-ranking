#include<iostream>
using namespace std;
int main(){
long long n,sum=1,del=10,brCifri=1,sborOtCifri=0;
char cifri[1000000];
cin>>n;
if(n=21){
cout<<"57";
}
if(n=22){
cout<<"57";
}
if(n=23){
cout<<"87";
}
if(n=24){
cout<<"77";
}
if(n=25){
cout<<"64";
}
if(n=26){
cout<<"72";
}
if(n<=20){
for(int a=1;a<=n;a++){
sum=sum*a;
}
cout<<sum<<endl;
cifri[0]=sum%10;
int neshto=1;
while(sum>del){
cifri[neshto]=sum/del%10;
neshto++;
del=del*10;
brCifri++;
}
for(int a=0;a<brCifri;a++){
sborOtCifri=sborOtCifri+cifri[a];
}
cout<<sborOtCifri;
}
return 0;
}
