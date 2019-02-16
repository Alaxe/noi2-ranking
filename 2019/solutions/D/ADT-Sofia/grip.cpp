#include <iostream>
using namespace std;

int main () {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ios_base::sync_with_stdio(false);
cout.tie(NULL);

string vhod;
long long den , mesec, godina=2019, kolkoDni;
cin>>vhod>>kolkoDni;
    if( vhod[2]=='/' ){
        den=(vhod[0]-'0')*10+vhod[1]-'0';
        if( vhod[5]=='/' ){
            mesec=(vhod[3]-'0')*10+vhod[4]-'0';
        }else{
            mesec=vhod[3]-'0';
        }
    }else{
        den=vhod[0]-'0';
        if( vhod[3]=='/' ){
            mesec=vhod[2]-'0';
        }else{
            mesec=(vhod[2]-'0')*10+vhod[3]-'0';
        }

    }

///cout<<den<<" "<<mesec<<" "<<godina;
    long long dniDo1qn=0;
for( long long i=0; i<mesec ; i++){
    if( i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12 ){
        dniDo1qn+=31;
    }
    if( i==2 ){
        dniDo1qn+=28;
    }
    if( i==4 or i==6 or i==9 or i==11){
        dniDo1qn+=30;
    }
}
dniDo1qn+=den;
bool dali=true;
long long denNaZapachvane=dniDo1qn%7+1, pochivniDni=0;
///cout<<denNaZapachvane;
while( pochivniDni != kolkoDni or denNaZapachvane==7 or denNaZapachvane==6 ){
    dali=true;
    if(denNaZapachvane!=6 && denNaZapachvane!=7){
        pochivniDni++;
    }
    if( mesec==12 and den==31 ){
        godina++;
        den=1;
        mesec=1;
    }
    if( mesec==1 or mesec==3 or mesec==5 or
        mesec==7 or mesec==8 or mesec==10 or mesec==12 ){
        if( den==31 ){
            mesec++;
            den=1;
            dali=false;
        }
    }
    if( mesec==2 ){
        if(den==28){
            mesec++;
            den=1;
            dali=false;
        }
    }
    if( mesec==4 or mesec==6 or mesec==9 or mesec==11){
        if(den==30){
            mesec++;
            den=1;
            dali=false;
        }
    }

    if(denNaZapachvane==7){
        denNaZapachvane=1;
    }else{
        denNaZapachvane++;
    }
    if( dali ){
        den++;
    }
///cout<<den<<" "<<mesec<<" "<<denNaZapachvane<<" "<<pochivniDni<<endl;
}
///cout<<den<<" "<<mesec<<" "<<godina;
if( den/10<=0 ){
    cout<<"0"<<den<<".";
}else{
    cout<<den<<".";
}
if( mesec/10<=0 ){
    cout<<"0"<<mesec<<".";
}else{
    cout<<mesec<<".";
}
 cout<<godina<<endl;
    return 0;
}
