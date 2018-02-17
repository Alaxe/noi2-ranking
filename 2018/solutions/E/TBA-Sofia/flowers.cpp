#include<iostream>
using namespace std;
int main (){
     long long brcwetia,cwetia[10000],brkapki,maxchislo=0,brputiIspolzwanaWoda=0;
     cin>>brcwetia;
     for(int a=0;a<brcwetia;a++){
          cin>>cwetia[a];
     }
     cin>>brkapki;
     for(int a=0;a<brcwetia;a++){
          if(cwetia[a]>maxchislo){
               maxchislo=cwetia[a];
          }
     }
     for(int a=0;a<brcwetia;a++){
          brputiIspolzwanaWoda+=(maxchislo-cwetia[a]);
     }
     cout<<brkapki*brputiIspolzwanaWoda;
    return 0;
}
