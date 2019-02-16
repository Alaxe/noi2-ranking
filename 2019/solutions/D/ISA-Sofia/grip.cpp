#include<bits/stdc++.h>
using namespace std;
long long sed=0,den,mes,g,izm=0,vak;
bool visokosna(int god){
    return (god%4==0 && god%100!=0) || god%400==0;
}
int koidensme(int day,int month,int godina){
    if(month==1){
        return day;
    }else if(month==2){
        return 31+day;
    }else if(month==3){
        return 31+28+day+visokosna(godina);
    }else if(month==4){
        return 31+28+31+day+visokosna(godina);
    }else if(month==5){
        return 31+28+31+30+day+visokosna(godina);
    }else if(month==6){
        return 31+28+31+30+31+day+visokosna(godina);
    }else if(month==7){
        return 31+28+31+30+31+30+day+visokosna(godina);
    }else if(month==8){
        return 31+28+31+30+31+30+31+day+visokosna(godina);
    }else if(month==9){
        return 31+28+31+30+31+30+31+31+day+visokosna(godina);
    }else if(month==10){
        return 31+28+31+30+31+30+31+31+30+day+visokosna(godina);
    }else if(month==11){
        return 31+28+31+30+31+30+31+31+30+31+day+visokosna(godina);
    }else if(month==12){
        return 31+28+31+30+31+30+31+31+30+31+30+day+visokosna(godina);
    }
}

void uvel(){
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10){
        if(den!=31){
            den++;
        }else{
            den=1;
            mes++;
        }
    }
    else if(mes==12){
        if(den!=31){
            den++;
        }else{
            den=1;
            mes=1;
            g++;
        }
    }else if(mes==4 || mes==6 || mes==9 || mes==11){
        if(den!=30){
            den++;
        }else{
            den=1;
            mes++;
        }
    }else if(mes==2){
        if(visokosna(g)){
            if(den!=29){
                den++;
            }else{
                den=1;
                mes++;
            }
        }else{
            if(den!=28){
                den++;
            }else{
                den=1;
                mes++;
            }
        }
    }
    if(sed%7>=1 && sed%7<=5){
        izm++;
    }
}

int main(){
    string vhod;
    int pos;
    cin>>vhod;
    cin>>vak;
    if(vhod[1]=='/'){
        den=vhod[0]-'0';
        pos=2;
    }else{
        den=(vhod[0]-'0')*10+vhod[1]-'0';
        pos=3;
    }
    mes=vhod[pos]-'0';
    pos++;
    if(vhod[pos]=='/'){
        pos++;
    }else{
        mes*=10;
        mes+=vhod[pos]-'0';
        pos++;
    }
    if(vhod[vhod.size()-1]=='9'){
        g=2019;
    }else{
        g=2020;
    }
    for(int i=1900;i<=g-1;i++){
        sed+=365+visokosna(i);
    }
    sed+=koidensme(den,mes,g);
    while(izm<vak){
        uvel();
        sed++;
    }
    if(sed%7==6){
        uvel();
        uvel();
    }else if(sed%7==0){
        uvel();
    }
    if(den<10){
        cout<<0;
    }
    cout<<den<<".";
    if(mes<10){
        cout<<0;
    }
    cout<<mes<<"."<<g;
    cout<<endl;
    return 0;
}
