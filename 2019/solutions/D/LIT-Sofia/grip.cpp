#include<bits/stdc++.h>
using namespace std;
int main(){
int d,m,y,n,denotgodinata=0,denotsedmica=0,purviuchebenden=0,br=0,c=0,a=0,den,mesec,godina;
char s,t;
cin>>d;
cin>>s;
cin>>m;
cin>>t;
cin>>y;
cin>>n;
for(int i=1;i<=m;i++){
  if(i<m){
  if(i==1 or i==3 or i==5 or i==7 or i==8 or i==10){
    denotgodinata=denotgodinata+31;
  }
  if(i==4 or i==6 or i==9 or i==11){
    denotgodinata=denotgodinata+30;
  }
  if(i==2 and y%4==0){
        denotgodinata=denotgodinata+29;
  }
  if(i==2 and y%4!=0){
        denotgodinata=denotgodinata+28;
  }
  }else{
        denotgodinata=denotgodinata+d;
  }
}
if(y==2019){
    denotsedmica=2+(denotgodinata-1)%7;
    denotsedmica=denotsedmica%7;
    if(denotsedmica==0){
        denotsedmica=7;
    }
}
if(y==2020){
    denotsedmica=3+(denotgodinata-1)%7;
    denotsedmica=denotsedmica%7;
    if(denotsedmica==0){
        denotsedmica=7;
    }
}
c=denotsedmica;
for(int i=denotgodinata;;i++){
  if(c%7==1 or c%7==2 or c%7==3 or c%7==4 or c%7==5){
    br++;
  }
 if(br==n){
     if(c%7==5){
        purviuchebenden=i+3;
     }
      if(c%7==6){
        purviuchebenden=i+2;
     }
      if(c%7==0 or c%7==1 or c%7==2 or c%7==3 or c%7==4){
        purviuchebenden=i+1;
     }
      if(y==2019 and purviuchebenden>365){
    purviuchebenden=purviuchebenden-365;
    godina=y+1;
 }else{
  if(y==2020 and purviuchebenden>366){
    purviuchebenden=purviuchebenden-366;
       godina=y+1;
 }else{
 godina=y;
 }
 }
 break;
 }

 c++;
}
br=0;
a=purviuchebenden;
for(int i=1;i<=12;i++){

        if(i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12){
            a=a-31;
            if(a<=0){
                mesec=i;
                a=a+31;
                den=a;
            }
        }else{
        if(i==4 or i==6 or i==9 or i==11){
            a=a-30;
             if(a<=0){
                mesec=i;
                a=a+30;
                den=a;
            }
        }else{
            if(godina==2020 and i==2){
                a=a-29;
             if(a<=0){
                mesec=i;
                a=a+29;
                den=a;
            }
            if(godina!=2020 and i==2){
                a=a-28;
             if(a<=0){
                mesec=i;
                a=a+28;
                den=a;
            }
        }
            }
        }

}
if(den<10){
    cout<<"0"<<den;
}else{
    cout<<den;
}
cout<<".";
if(mesec<10){
     cout<<"0"<<mesec;
}else{
    cout<<mesec;
}
cout<<".";
cout<<godina<<endl;
}
return 0;
}
