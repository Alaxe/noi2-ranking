#include<bits/stdc++.h>
using namespace std;
int main(){
    //vavejdane
    string data;
    long long dni;
    cin>>data>>dni;
    long long den=0, mesec=0, godina=0, po=1;
    //prevrashtane v long long promenlivi
    string naKoe="godina";
    for(long long i=data.size()-1;i>=0;i--){
        if(data[i]!='/'){
            if(naKoe=="godina")godina+=(data[i]-'0')*po; else{
                if(naKoe=="mesec")mesec+=(data[i]-'0')*po; else den+=(data[i]-'0')*po;
            }
            po*=10;
        }else{
            po=1;
            if(naKoe=="godina")naKoe="mesec"; else naKoe="den";
        }
    }
    //prevrashtane samo v dni
    if(godina==2020)den+=365;
    if(mesec>2){
        if(godina==2020)den+=29; else den+=28;
    }
    if(mesec>3)den+=31;
    if(mesec>4)den+=30;
    if(mesec>5)den+=31;
    if(mesec>6)den+=30;
    if(mesec>7)den+=31;
    if(mesec>8)den+=31;
    if(mesec>9)den+=30;
    if(mesec>10)den+=31;
    if(mesec>11)den+=30;
    godina=2019;
    mesec=1;
    //dobavqne na vakanciqta
    while(dni>0){
            if((den-5)%7!=0 && (den-6)%7!=0)dni--;
            den++;
    }
    if((den-5)%7==0)den+=2; else{
        if((den-6)%7==0)den++;
    }
    //obratno kam data
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>28){
        mesec++;
        den-=28;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        godina=2020;
        mesec=1;
        den-=31;
    }
    if(den>29){
        mesec++;
        den-=29;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    if(den>30){
        mesec++;
        den-=30;
    }
    if(den>31){
        godina=2021;
        mesec=1;
        den-=31;
    }
    if(den>28){
        mesec++;
        den-=28;
    }
    if(den>31){
        mesec++;
        den-=31;
    }
    //izvejdane
    cout<<den/10<<den%10<<"."<<mesec/10<<mesec%10<<"."<<godina<<endl;
    return 0;
}
