#include<iostream>
using namespace std;
int main (){

long long a,b,n,turceno,broicifri=0,suvpadeniq=0;;
cin>>n;
a=n;

if(a>11){
    while(a%11!=0){
        a=a-1;
    }


for(int j=1;b<n;j=j+1){

b=n-j;

turceno=a*b;
while(turceno>0){
    broicifri++;
    turceno=turceno/10;


}
turceno=a*b;
long long c[broicifri];
for(int s=0;s<broicifri;s=s+1){
    c[s]=turceno%10;
    turceno/10;
}
for(int k=0;k<broicifri/2;k=k+1){
if(c[k]==c[broicifri-k])
{
    suvpadeniq=suvpadeniq+1;
}
}
if(suvpadeniq==broicifri/2){
    n=0;}
    else suvpadeniq=0;

}
if(a>b)cout<<b<<" "<<a<<endl<<a*b;
else cout<<a<<" "<<b<<endl<<a*b;
}
if(a<11){
    a=1;
b=n-1;

cout<<a<<" "<<b<<endl<<a*b;
}
if(a==11)
{

    b=1;
    a=11-2;
    cout<<b<<" "<<a<<endl<<a*b;
}
return 0;
}
