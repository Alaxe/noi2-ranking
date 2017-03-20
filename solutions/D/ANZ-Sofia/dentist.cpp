#include<iostream>
using namespace std;
int main (){
char lol[100];
long long doshul[50], vreme[50], i=0, big=0, n[50], a;
for(i=0;i<4;i++){
    cin>>doshul[i]>>vreme[i];
    if(doshul[i]>big){
        big=doshul[i];
        for(a=0;a<50;a++){
            if(n[a]==1){
                n[a]=50;
            }
        }
        n[i]=1;
    }
}
for(i=0;i<50;i++){
    if(n[i]==1){
        cout<<vreme[i];
    }
}
return 0;
}
