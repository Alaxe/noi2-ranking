#include <iostream>
using namespace std;
int main (){
int last=1,lost,b,c,a,sheep=1,numbersheep=1;
cin>>sheep;
cin>>lost;

if(lost==1)
{
    cin>>a;
    b=a;
    c=a;
}
if(lost==2){
    cin>>a>>b;
    c=a;}
if(lost==3){
cin>>a>>b>>c;}
while(sheep>0){
numbersheep=last;
     last++;

while(numbersheep%10!=a&&numbersheep%10!=b&&numbersheep%10!=c&&numbersheep!=0){
    numbersheep/=10;

    if(numbersheep==0)
        sheep--;}

}
cout<<last-2;

}
