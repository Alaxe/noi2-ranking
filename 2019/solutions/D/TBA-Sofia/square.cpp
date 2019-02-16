#include<iostream>
using namespace std;
int main(){
    bool razdeliLiSe=false;
    int brChisla,chisla[10000],neshto=1;
    cin>>brChisla;

    for(int a=0;a<brChisla;a++){

        cin>>chisla[a];
    }
    for(int a=0;a<5;a++){
    for(int b=0;b<brChisla;b++){

    if(chisla[b]%2==0){
        chisla[b]/=2;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=2;

        razdeliLiSe=false;
    }else{
      break;
    }



    }
    for(int a=0;a<3;a++){
    for(int b=0;b<brChisla;b++){

    if(chisla[b]%3==0){
        chisla[b]/=3;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=3;
        razdeliLiSe=false;
    }else{
      break;
    }
    }


    for(int a=0;a<2;a++){
    for(int b=0;b<brChisla;b++){

    if(chisla[b]%5==0){
        chisla[b]/=5;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=5;
        razdeliLiSe=false;
    }else{
      break;
    }
    }



    for(int b=0;b<brChisla;b++){

    if(chisla[b]==0){
        chisla[b]/=7;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=7;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%11==0){
        chisla[b]/=11;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=11;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%13==0){
        chisla[b]/=13;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=13;
        razdeliLiSe=false;
    }



    for(int b=0;b<brChisla;b++){

    if(chisla[b]%13==0){
        chisla[b]/=13;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=13;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%17==0){
        chisla[b]/=17;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=17;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%19==0){
        chisla[b]/=19;
        razdeliLiSe=true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=19;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%23==0){
        chisla[b]/=23;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=23;
        razdeliLiSe=false;
    }


      for(int b=0;b<brChisla;b++){

    if(chisla[b]%23==0){
        chisla[b]/=23;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=23;
        razdeliLiSe=false;
    }


      for(int b=0;b<brChisla;b++){

    if(chisla[b]%29==0){
        chisla[b]/=29;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=29;
        razdeliLiSe=false;
    }


      for(int b=0;b<brChisla;b++){

    if(chisla[b]%31==0){
        chisla[b]/=31;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=31;
        razdeliLiSe==false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%37==0){
        chisla[b]/=37;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=37;
        razdeliLiSe=false;
    }


    for(int b=0;b<brChisla;b++){

    if(chisla[b]%41==0){
        chisla[b]/=41;
        razdeliLiSe==true;
        }
    }
    if(razdeliLiSe==true){
        neshto*=41;
        razdeliLiSe=false;
    }


    cout<<neshto/2;
    return 0;
}
