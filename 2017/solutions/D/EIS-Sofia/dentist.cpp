#include<iostream>
using namespace std;
int main (){
long long minutiSledLekar[1000],vremeZaRabota[1000],i=0,j,k,x=0,m=0,vreme=0,zakusnenie=0;
for(i=0; i<5; i++){
    cin>>minutiSledLekar[i]>>vremeZaRabota[i];

}
for(j=0; j<5; j++){
for(i=0; i<5; i++){
    if(minutiSledLekar[i]>minutiSledLekar[i+1]){
        k=minutiSledLekar[i];
        minutiSledLekar[i]=minutiSledLekar[i+1];
        minutiSledLekar[i+1]=k;
        m=vremeZaRabota[i];
        vremeZaRabota[i]=vremeZaRabota[i+1];
        vremeZaRabota[i+1]=m;
    }

}
}
if(minutiSledLekar[4]+vremeZaRabota[4]<=720){
    cout<<vremeZaRabota[4];
}else{

    for(i=0; i<5; i++){
        if(vreme!=720){
            if(minutiSledLekar[i]+vremeZaRabota[i]<=720){
                vreme+=vremeZaRabota[i];

            }else{
                vreme=720;
                zakusnenie+=minutiSledLekar[i]+vremeZaRabota[i]-720;
            }
        }else{
            for(j=i; j<5; j++){
                zakusnenie+=vremeZaRabota[i];

            }

        }

    cout<<zakusnenie;

}
return 0;
}
