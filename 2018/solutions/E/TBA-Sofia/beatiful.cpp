#include<iostream>
using namespace std;
int main (){
     bool tervelEGotin=true;
     long long brcifri,delimo,naimalkochislo;
    cin>>brcifri>>delimo;
    if(brcifri==1){
        naimalkochislo=1;
    }
    if(brcifri==2){
        naimalkochislo=10;
    }
    if(brcifri==3){
        naimalkochislo=100;
    }
    if(brcifri==4){
        naimalkochislo=1000;
    }
    if(brcifri==5){
        naimalkochislo=10000;
    }
    if(brcifri==6){
        naimalkochislo=100000;
    }
    if(brcifri==7){
        naimalkochislo=1000000;
    }
    if(brcifri==8){
        naimalkochislo=10000000;
    }
    if(brcifri==9){
        naimalkochislo=100000000;
    }
    if(brcifri==10){
        naimalkochislo=1000000000;
    }
    if(brcifri==11){
        naimalkochislo=10000000000;
    }
    if(brcifri==12){
        naimalkochislo=100000000000;
    }
    if(brcifri==13){
        naimalkochislo=1000000000000;
    }
    if(brcifri==14){
        naimalkochislo=10000000000000;
    }
    if(brcifri==15){
        naimalkochislo=100000000000000;
    }
    if(brcifri==16){
        naimalkochislo=1000000000000000;
    }
    if(brcifri==17){
        naimalkochislo=10000000000000000;
    }
    if(brcifri==18){
        naimalkochislo=100000000000000000;
    }
    while(tervelEGotin){
     if(naimalkochislo%delimo!=0){
          naimalkochislo++;
     }else{
          tervelEGotin=false;
     }
    }
       cout<<naimalkochislo;
    return 0;
}
