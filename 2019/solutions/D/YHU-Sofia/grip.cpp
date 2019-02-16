#include<cstring>
#include<iostream>
using namespace std;
int main(){
char nachalo[10];
long i,produlji,data=0,mesec=0,godina,den;
cin>>nachalo>>produlji;
for(i=0;i<strlen(nachalo)-1;i++){
    if(nachalo[i+1]!='/' and nachalo[i]!='/'){
       data=(data+nachalo[i]-'0')*10;
    }else if(nachalo[i+1]=='/'){
       data=data+nachalo[i]-'0';
    }
    if(nachalo[i]=='/'){
      break;
    }
}

for(i=i+1;i<strlen(nachalo)-1;i++){
    if(nachalo[i+1]!='/' and nachalo[i]!='/'){
       mesec=(mesec+nachalo[i]-'0')*10;
    }else if(nachalo[i+1]=='/'){
       mesec=mesec+nachalo[i]-'0';
    }
    if(nachalo[i]=='/'){
      break;
    }
}
if(nachalo[strlen(nachalo)-1]=='9'){
   godina=2019;
}
else{
   godina=2020;
}
produlji=(produlji/5)*7+produlji%5;
data=data+produlji;
if((mesec==4 or mesec==6 or mesec==9 or mesec==11) and  data>30){
    if(data>61){
     data=data-61;
     mesec=mesec+2;}else{
     data=data-30;
     mesec++;
     }
}
else if(mesec==1 and data>31){
  if(godina==2019 and data>59){
  data=data-59;
  mesec=mesec+2;
  }
  if(godina==2020 and data>60){
  data=data-60;
  mesec=mesec+2;
  }else{
     data=data-30;
     mesec++;
  }

}
else if((mesec==3 or mesec==5 or mesec==7 or mesec==8 or mesec==10 or mesec==12) and data>31){
       data=data-31;
       mesec++;
}
if(mesec>12){
  mesec=mesec-12;
  godina++;
}
if(mesec<10 and data<10){
cout<<"0"<<data+1<<".0"<<mesec<<"."<<godina;
}else if(data>9 and mesec<10){
cout<<data<<".0"<<mesec<<"."<<godina;
}else if(data<10 and mesec>9){
cout<<data<<"."<<mesec<<".0"<<godina;
}else{
cout<<data<<"."<<mesec<<"."<<godina;
}
return 0;
}
