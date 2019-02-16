#include<iostream>
using namespace std;
int delnikLiE[1095];
bool visokosnaLiE(int godina){
    if(godina == 2020){
        return true;
    }
    return false;
}

int main(){
    int x = 0;
    delnikLiE[0] = 1;
    for(int i = 4;i < 1095;++i){
        if(x < 5){
            delnikLiE[i] = 1;
        }
        x++;
        if(x == 6){
            x = 0;
        }
    }

    int broi = 0;
    int den, mesec, godina;
    int dyljina;
    char znak;
    cin>>den>>znak>>mesec>>znak>>godina;
    cin>>dyljina;

        int i = 5;
        while(i < dyljina){
            if(delnikLiE[i] == 1)
               i++;
            broi++;
        }
        dyljina += broi;
    if(mesec == 1 || mesec == 3 || mesec == 5 || mesec == 7 || mesec == 8 || mesec == 10 || mesec == 12){
        if(den + dyljina >= 32){
            den = dyljina - (31 - den);
            mesec++;
        }
        else{
            den+=dyljina;
        }
        if(mesec > 12){
            mesec = 1;
            godina++;
        }
        if(den <= 9){
            cout<<"0"<<den+1<<".";
        }else{
            cout<<den+1<<".";
        }
        if(mesec <= 9){
            cout<<"0"<<mesec<<"."<<godina<<endl;
        }else{
            cout<<mesec<<"."<<godina<<endl;
        }
        return 0;
    }
    if(mesec == 4 || mesec == 6 || mesec == 8 || mesec == 10){
        if(den + dyljina >= 31){
            den = dyljina - (30 - den);
            den--;
            mesec++;
        }else{
            den += dyljina;
        }
        if(den <= 9){
            cout<<"0"<<den<<".";
        }else{
            cout<<den<<".";
        }
        if(mesec <= 9){
            cout<<"0"<<mesec<<"."<<godina<<endl;
        }else{
            cout<<mesec<<"."<<godina<<endl;
        }
        return 0;
    }
    if(mesec == 2 && visokosnaLiE(godina)){
        if(den + dyljina >= 30){
            den = dyljina - (29 - den);
            mesec++;
        }else{
            den+=dyljina;
        }
         if(den <= 9){
            cout<<"0"<<den<<".";
        }else{
            cout<<den<<".";
        }
        if(mesec <= 9){
            cout<<"0"<<mesec<<"."<<godina<<endl;
        }else{
            cout<<mesec<<"."<<godina<<endl;
        }
        return 0;
    }
    if(mesec == 2 && visokosnaLiE(godina) == 0){
        if(den + dyljina >= 29){
            den = dyljina - (28 - den);
            mesec++;
        }else{
            den += dyljina;
        }
        if(den <= 9){
            cout<<"0"<<den<<".";
        }else{
            cout<<den<<".";
        }
        if(mesec <= 9){
            cout<<"0"<<mesec<<"."<<godina<<endl;
        }else{
            cout<<mesec<<"."<<godina<<endl;
        }
        return 0;
    }
    return 0;
}

