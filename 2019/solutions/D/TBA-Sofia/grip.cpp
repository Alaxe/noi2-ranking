#include<iostream>
using namespace std;
int main(){
    char a;
    int den,mesec,godina,brDni;
    cin>>den>>a>>mesec>>a>>godina>>brDni;
    den+=brDni;

    cout<<den<<endl;
        if(mesec%2==1 && mesec<8 && den>31){
            den-=31;
            mesec++;
        }
        if(mesec%2==2 && mesec<8 && den>30){
            den-=30;
            mesec++;
        }
        if(mesec==2 ){
            if(godina%4==0 && godina%100+10!=10 && den>29){
                den-=29;
                mesec++;
            }
            if(godina%4!=0  && den>28){
                den-=28;
                mesec++;
            }
        }
        if(mesec%2==1 && mesec>7 && den>30){
            den-=30;
            mesec++;
        }
        if(mesec%2==0 && mesec>7 && den>31){
            den-=31;
            mesec++;


    }
    if(mesec>12){
        godina++;
    }
    if(den<10){
        cout<<'0'<<den<<'.';
    }
    else{
        cout<<den<<'.';
    }
    if(mesec<10){
        cout<<'0'<<mesec<<'.';
    }
    else{
        cout<<mesec<<'.';
    }
    cout<<godina;
    return 0;
}

