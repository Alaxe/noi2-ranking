#include<iostream>
using namespace std;
int main(){
   char nenuj;
long long d,m,g,prod;
cin>>d>>nenuj>>m>>nenuj>>g>>prod;
long long den;
den=1+(g-1900 + d-1)%7;
for(;prod>0;d++ and den++){
      if(den==8){
      den=1;
      }
if(prod>0 and den<6){
   prod--;
}
}
if(den==5){
   d+=2;
}if(den==6){
d+=1;
}

if(g==2019){
if((m==4 or m==6 or m==9 or m==11) and d>=31){
   d-=30;
   m+=1;
}
   if(m==2 and d>=29){
      d-=28;
      m=3;
   }if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12) and d>=32){
      m+=1;
      d-=31;
   }
if(d<28){
if(d<10){
   cout<<"0"<<d;
}else{
   cout<<d;
   }if(m<10){
cout<<".0"<<m<<".";
}else{
   cout<<"."<<m<<".";
}
   cout<<g;
   cout<<endl; return 0;
}else{
if((m==4 or m==6 or m==9 or m==11) and d>=31){
   d-=30;
   m+=1;
}
   if(m==2 and d>=29){
      d-=28;
      m=3;
   }if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12) and d>=32){
      m+=1;
      d-=31;
   }
}
if(d<28){
if(d<10){
   cout<<"0"<<d;
}else{
   cout<<d;
   }if(m<10){
cout<<".0"<<m<<".";
}else{
   cout<<"."<<m<<".";
}
   cout<<g;
   cout<<endl; return 0;
}
}else{
if((m==4 or m==6 or m==9 or m==11) and d>=31){
   d-=30;
   m+=1;
}
   if(m==2 and d>=30){
      d-=29;
      m=3;
   }if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12) and d>=32){
      m+=1;
      d-=31;
   }
   if(d<28){
if(d<10){
   cout<<"0"<<d;
}else{
   cout<<d;
   }if(m<10){
cout<<".0"<<m<<".";
}else{
   cout<<"."<<m<<".";
}
   cout<<g;
   cout<<endl; return 0;
}else{
   if((m==4 or m==6 or m==9 or m==11) and d>=31){
   d-=30;
   m+=1;
}
   if(m==2 and d>=30){
      d-=29;
      m=3;
   }if((m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12) and d>=32){
      m+=1;
      d-=31;
   }
}

if(d<10){
   cout<<"0"<<d;
}else{
   cout<<d;
   }if(m<10){
cout<<".0"<<m<<".";
}else{
   cout<<"."<<m<<".";
}
   cout<<g;

   cout<<endl; return 0;

   }

return 0;
}
