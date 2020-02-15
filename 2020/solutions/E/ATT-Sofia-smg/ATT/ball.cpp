#include<iostream>
using namespace std;
int main(){
long long n, x, nachalenNomer, ch0=0, ch1=0, ch2=0;
cin>>n>>x;
if(x==0){
    ch0=1;
}
if(x==1){
    ch1=1;
}
if(x==2){
    ch2=1;
}
if(n%2==1){
    for(n=n;n=0 && n%2==1;n=n-1){
    swap(ch2, ch1);
}
     for(n=n;n=0 && n%2==0;n=n-1){
    swap(ch0, ch1);
}
}
if(n%2==0){
    for(n=n;n=0 && n%2==0;n=n-1){
    swap(ch0, ch1);
}
     for(n=n;n=0 && n%2==1;n=n-1){
    swap(ch2, ch1);
}
}
if(ch0==1){
    ch0=0;
    ch2=1;
}
if(ch1==1){
    ch1=0;
    ch0=1;
}
if(ch2==1){
    ch2=0;
    ch1=1;
}
if(ch0==1){
    nachalenNomer=0;
}
if(ch1==1){
    nachalenNomer=1;
}
if(ch2==1){
    nachalenNomer=2;
}
cout<<nachalenNomer;
return 0;
}
