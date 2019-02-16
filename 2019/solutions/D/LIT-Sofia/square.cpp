#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0;
cin>>n;
int arr[n];
long long chislo=1;
for(int x=0;x<n;x++){
   cin>>arr[x];
}
for(int y=0;y<n;y++){

}
if(a%2==0){
   chislo=chislo*pow(2,a/2);
}
if(a%2==1){
    chislo=chislo*pow(2,a/2+1);
}
if(b%2==0){
   chislo=chislo*pow(3,b/2);
}
if(b%2==1){
    chislo=chislo*pow(3,b/2+1);
}
if(c%2==0){
   chislo=chislo*pow(5,a/2);
}
if(c%2==1){
    chislo=chislo*pow(5,a/2+1);
}
if(d%2==0){
   chislo=chislo*pow(7,a/2);
}
if(d%2==1){
    chislo=chislo*pow(7,a/2+1);
}
if(e%2==0){
   chislo=chislo*pow(11,a/2);
}
if(e%2==1){
    chislo=chislo*pow(11,a/2+1);
}
if(f%2==0){
   chislo=chislo*pow(13,a/2);
}
if(f%2==1){
    chislo=chislo*pow(13,a/2+1);
}
if(g%2==0){
   chislo=chislo*pow(17,a/2);
}
if(g%2==1){
    chislo=chislo*pow(17,a/2+1);
}
if(h%2==0){
   chislo=chislo*pow(19,a/2);
}
if(h%2==1){
    chislo=chislo*pow(19,a/2+1);
}
if(i%2==0){
   chislo=chislo*pow(23,a/2);
}
if(i%2==1){
    chislo=chislo*pow(23,a/2+1);
}
if(j%2==0){
   chislo=chislo*pow(29,a/2);
}
if(j%2==1){
    chislo=chislo*pow(29,a/2+1);
}
if(k%2==0){
   chislo=chislo*pow(31,a/2);
}
if(k%2==1){
    chislo=chislo*pow(31,a/2+1);
}
if(l%2==0){
   chislo=chislo*pow(37,a/2);
}
if(l%2==1){
    chislo=chislo*pow(37,a/2+1);
}
if(m%2==0){
   chislo=chislo*pow(41,a/2);
}
if(m%2==1){
    chislo=chislo*pow(41,a/2+1);
}

cout<<chislo<<endl;

return 0;
}
