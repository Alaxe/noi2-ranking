#include<bits/stdc++.h>
using namespace std;
int d,m,g,i,f,n,c,d2,m2,g2;
char k;
void data(){
if(c==6 or c==7){
n++;
}
while(n>0){
d++;
if((m==4 or m==6 or m==9 or m==11) and d==31){
d=1;
m++;
}else if((m==2 and g%4>0) and d==29){
d=1;
m++;
}else if(m==2 and g%4==0 and d==30){
d=1;
m++;
}else if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12) and d==32){
d=1;
m++;
}
if(m==13){
m=1;
d=1;
g++;
}
n--;
c++;
if(c==8){
c=1;
}
if(c==6 or c==7){
n++;
}
}
}
int main(){
c=2;
d2=1;
m2=1;
g2=2019;
cin>>d>>k>>m>>k>>g>>n;
while(d2!=d or m2!=m or g2!=g){
d2++;
if((m2==4 or m2==6 or m2==9 or m2==11) and d2==31){
d2=1;
m2++;
}else if((m2==2 and g2%4>0) and d2==29){
d2=1;
m2++;
}else if(m2==2 and g2%4==0 and d2==30){
d2=1;
m2++;
}else if((m2==1 or m2==3 or m2==5 or m2==7 or m2==8 or m2==10 or m2==12) and d2==32){
d2=1;
m2++;
}
if(m2==13){
m2=1;
d2=1;
g2++;
}
c++;
if(c==8){
c=1;
}
}
data();
if(d<10){
cout<<0;
}
cout<<d<<".";
if(m<10){
cout<<0;
}
cout<<m<<"."<<g<<endl;
return 0;
}
