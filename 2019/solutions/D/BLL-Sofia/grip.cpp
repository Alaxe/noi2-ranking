#include<iostream>
using namespace std;
int main(){
string data;
long long den,mesec,godina,dni,i,denOtSedmicata=5,mesec1=1,godina1=2019,den1=1;
bool namerihmeLiDenq=false;
cin>>data>>dni;
if(data[2]=='/'){
    den=(data[0]-'0')*10+data[1]-'0';
    if(data[4]=='/'){
        mesec=data[3]-'0';
        godina=(data[5]-'0')*1000+(data[6]-'0')*100+(data[7]-'0')*10+data[8]-'0';
    }else{
        mesec=(data[3]-'0')*10+data[4]-'0';
        godina=(data[6]-'0')*1000+(data[7]-'0')*100+(data[8]-'0')*10+data[9]-'0';
    }
}else{
    den=data[0]-'0';
    if(data[3]=='/'){
        mesec=data[2]-'0';
        godina=(data[4]-'0')*1000+(data[5]-'0')*100+(data[6]-'0')*10+data[7]-'0';
    }else{
        mesec=(data[2]-'0')*10+data[3]-'0';
        godina=(data[5]-'0')*1000+(data[6]-'0')*100+(data[7]-'0')*10+data[8]-'0';
    }
}
while(!namerihmeLiDenq){
    if(!(mesec1==mesec and den==den1 and godina1==godina)){
    den1++;
    denOtSedmicata++;
    if(denOtSedmicata==8){
        denOtSedmicata=1;
    }
    if(mesec1==13){
        mesec1=1;
        godina1++;
    }
    if(mesec1==1 or mesec1==3 or mesec1==5 or mesec1==7 or mesec1==8 or mesec1==10 or mesec1==12){
        if(den1==32){
            mesec1++;
            den1=1;
        }
    }
    if(mesec1==4 or mesec1==6 or mesec1==9 or mesec1==11 ){
        if(den1==31){
            mesec1++;
            den1=1;
        }
    }
    if(mesec1==2){
        if(den1==29 and godina1%4!=0){
            mesec1++;
            den1=1;
        }
        if(den1==30 and godina1%4==0){
            mesec1++;
            den1=1;
        }
    }
    }else{
        namerihmeLiDenq=true;
    }
}
if(denOtSedmicata==8){
    denOtSedmicata=1;
}
for(i=dni;i>0;i--){
    if(denOtSedmicata==7){
        den+=1;
        denOtSedmicata=1;
    }else{
    if(denOtSedmicata==6){
        den+=3;
        denOtSedmicata=1;
    }else{
    den++;
    denOtSedmicata++;
    }
    }
    if(mesec==13){
        mesec=1;
        godina++;
    }
    if(mesec==14){
        mesec=2;
        godina++;
    }
    if(mesec==1 or mesec==3 or mesec==5 or mesec==7 or mesec==8 or mesec==10 or mesec==12){
        if(den==32){
            mesec++;
            den=1;
        }
        if(den==33){
           mesec++;
           den=2;
        }
        if(den==34){
            mesec++;
           den=3;
        }
    }
    if(mesec==4 or mesec==6 or mesec==9 or mesec==11 ){
        if(den==31){
            mesec++;
            den=1;
        }
        if(den==32){
           mesec++;
           den=2;
        }
        if(den==33){
            mesec++;
           den=3;
        }
    }
    if(mesec==2){
        if(den==29 and godina%4!=0){
            mesec++;
            den=1;
        }
        if(den==30 and godina%4==0){
            mesec++;
            den=1;
        }
        if(den==33){
           mesec++;
           den=2;
        }
        if(den==34){
            mesec++;
           den=3;
        }
    }
}
if(den>9 and mesec>9){
cout<<den<<"."<<mesec<<"."<<godina<<endl;
}
if(den<10 and mesec1<10){
cout<<"0"<<den<<"."<<"0"<<mesec<<"."<<godina<<endl;
}
if(den>9 and mesec1<10){
cout<<den<<"."<<"0"<<mesec<<"."<<godina<<endl;
}
if(den<10 and mesec1>9){
cout<<"0"<<den<<"."<<mesec<<"."<<godina<<endl;
}
return 0;
}
