#include <iostream>
#include <cstring>
using namespace std;
long meseci[13][2],kolkoDena;
int main(){
char data[12];
cin>>data>>kolkoDena;
long long index,den=0,mesec=0,godina=0,kolko,dulshina=strlen(data)-1,kolkoDenaOstavatDoMesec,index2,koiDen=1,den2,mesec2,godina2;
long long denq[1096];
bool visokosna;
for(index=0,index2=1;index<1096;index++){
    denq[index]=index2;
    if(index2+1==7){
        index2=0;
    }else{
        index2++;
    }
}
meseci[1][0]=31;meseci[1][1]=31;meseci[2][0]=28;meseci[2][1]=29;meseci[3][0]=31;meseci[3][1]=31;meseci[4][0]=30;meseci[4][1]=30;meseci[5][0]=31;meseci[5][1]=31;meseci[6][0]=30;meseci[6][1]=30;meseci[7][0]=31;meseci[7][1]=31;meseci[8][0]=31;meseci[8][1]=31;meseci[9][0]=30;meseci[9][1]=30;meseci[10][0]=31;meseci[10][1]=31;meseci[11][0]=30;meseci[11][1]=30;meseci[12][0]=31;meseci[12][1]=31;
for(index=0,kolko=1,kolko=1;index<4;index++,kolko=kolko*10,dulshina--){
    godina=godina+(data[dulshina]-'0')*kolko;
}
dulshina--;
for(index=0,kolko=1,kolko=1;data[dulshina]>='0' && data[dulshina]<='9';index++,kolko=kolko*10,dulshina--){
    mesec=mesec+(data[dulshina]-'0')*kolko;
}
dulshina--;
for(index=0,kolko=1,kolko=1;data[dulshina]>='0' && data[dulshina]<='9';index++,kolko=kolko*10,dulshina--){
    den=den+(data[dulshina]-'0')*kolko;
}
if(godina==2019){
    visokosna=false;
}else{
    visokosna=true;
}
if(godina==2020){
    koiDen=365;
}
for(index=0;index<mesec;index++){
    koiDen=koiDen+meseci[index][visokosna];
}
koiDen=koiDen+den;
koiDen--;
while(kolkoDena>0){
        koiDen++;
        if(denq[koiDen]<5){
            kolkoDena--;
        }
        den++;
        if(den==meseci[mesec][visokosna]){
            mesec++;
            den=1;
        }
        if(mesec==12){
            godina++;
            den=0;
            mesec=1;
            if(godina==2019){
                visokosna=false;
            }
            if(godina==2021){
                visokosna=false;
            }
            if(godina==2020){
                visokosna=true;
            }
        }
}
den--;
if(den/10==0){
    cout<<"0";
}
cout<<den<<".";
if(mesec/10==0){
    cout<<"0";
}
cout<<mesec<<"."<<godina;
return 0;
}
