#include<iostream>
using namespace std;
int main(){
long long A,i,kopiei,broi=0,B,staroB,dulgo=0,Istina=0,kopiei2,kopiei3;
cin>>A;
for(i=1;i<=A;i++){
    kopiei=i;
    kopiei2=i;
    kopiei3=i;
    staroB=kopiei%10;
    dulgo=0;
    Istina=0;
    while(kopiei>0 && B==staroB){
        B=kopiei%10;
        kopiei=kopiei/10;
        dulgo=dulgo+1;
    }
        while(kopiei2>0){
        B=kopiei2%10;
        kopiei2=kopiei2/10;
        Istina=Istina+1;
    }
    if(Istina==dulgo) broi=broi+1;
    if(kopiei3%10==i) broi=broi+1;
}
cout<<broi<<endl;
return 0;
}
