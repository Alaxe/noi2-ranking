#include<iostream>
using namespace std;
int main(){
///01.01.2019 - vtornik
long long godina=0,denOtSedmica=2,den=0,mesec=0,d=0,m=0,g=0,brDni,purviDen=1,purviMesec=1,purvaGodina=2019;
char vhod[11];
cin>>vhod;
cin>>brDni;
for(long long i=0;vhod[i]!='/';i++){
    d=i;
}
den+=vhod[d]-'0';
if(d>0){
    den+=(vhod[d-1]-'0')*10;
}
for(long long i=d+2;vhod[i]!='/';i++){
    m=i;
}
mesec+=vhod[m]-'0';
if(m>d+2){
    mesec+=(vhod[m-1]-'0')*10;
}
for(long long i=m+2;vhod[i]!='\0';i++){
    g=i;
}
godina+=vhod[g]-'0';
godina+=(vhod[g-1]-'0')*10;
godina+=(vhod[g-2]-'0')*100;
godina+=(vhod[g-3]-'0')*1000;
while(purviDen<den){
    if(denOtSedmica>=7){
        denOtSedmica-=7;
    }
    denOtSedmica++;
    purviDen++;
}
while(purvaGodina<godina){
    if(denOtSedmica>=7){
        denOtSedmica-=7;
    }
    if(purvaGodina%4==0){
        denOtSedmica+=366;
    }else{
        denOtSedmica+=365;
    }
    purvaGodina++;
}
while(purviMesec<mesec){
    while(denOtSedmica>=7){
        denOtSedmica-=7;
    }
    if(purviMesec==4 or purviMesec==6 or purviMesec==9 or purviMesec==11){
        denOtSedmica+=30;
    }else{
        if(purviMesec==2){
            if(purvaGodina%4==0){
                denOtSedmica+=29;
            }else{
                denOtSedmica+=28;
            }
        }else{
            denOtSedmica+=31;
        }
    }
    purviMesec++;
}
while(brDni>0){
    if(denOtSedmica>=7){
        denOtSedmica-=7;
    }
    if(denOtSedmica<6){
        denOtSedmica++;
        den++;
        brDni--;
    }else{
        denOtSedmica++;
        den++;
    }
}
den+=3;
if(mesec==4 or mesec==6 or mesec==9 or mesec==11){
    while(den>30){
        den-=30;
        mesec++;
    }
    }else{
        if(mesec==2){
            if(godina%4==0){
                while(den>29){
                    den-=29;
                    mesec++;
                }
            }else{
                while(den>28){
                    den-=28;
                    mesec++;
                }
            }
        }else{
            while(den>31){
                den-=31;
                mesec++;
            }
        }
}
while(mesec>12){
    mesec-=12;
    godina++;
}
if(den<10 and mesec<10){
    cout<<0<<den<<"."<<0<<mesec<<"."<<godina;

}else{
    if(den<10){
        cout<<0<<den<<"."<<mesec<<"."<<godina;
    }else{
        if(mesec<10){
            cout<<den<<"."<<0<<mesec<<"."<<godina;
        }else{
            cout<<den<<"."<<mesec<<"."<<godina;
        }
    }
}
return 0;
}
