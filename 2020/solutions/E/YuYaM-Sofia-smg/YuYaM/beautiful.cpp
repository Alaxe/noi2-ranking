#include<iostream>
using namespace std;
int main ()
{
long long brKrasiviChisla=0,kopieI;
long long n;
cin>>n;
for(long long i=1; i<=n; i++){
    if(i<100 && i>10 && i%11==0){
        brKrasiviChisla=brKrasiviChisla+1;

    }
if(i*1==111||i*1==222||i*1==333||i*1==444||i*1==555||i*1==666||i*1==777||i*1==888||i*1==999){
    brKrasiviChisla=brKrasiviChisla+1;
}if(i*1==1111||i*1==2222||i*1==3333||i*1==4444||i*1==5555||i*1==6666||i*1==7777||i*1==8888||i*1==9999){
    brKrasiviChisla=brKrasiviChisla+1;
}
if(i*1==11111||i*1==22222||i*1==33333||i*1==44444||i*1==55555||i*1==66666||i*1==77777||i*1==88888||i*1==99999){
    brKrasiviChisla=brKrasiviChisla+1;
}
if(i*1==111111||i*1==222222||i*1==333333||i*1==444444||i*1==555555||i*1==666666||i*1==777777||i*1==888888||i*1==999999){
    brKrasiviChisla=brKrasiviChisla+1;
}
if(i==10 ){
    brKrasiviChisla=brKrasiviChisla+9;
}
kopieI=i;

}

if (kopieI<10){
    brKrasiviChisla=n;
}
cout<<brKrasiviChisla;

}
