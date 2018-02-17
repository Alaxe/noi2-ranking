#include <iostream>
using namespace std;
int main (){
int needed=0,a=0,all=0,broiflowers,kapki=0,highest=0;
cin>>broiflowers;
kapki=broiflowers;
while(broiflowers>0){
cin>>a;
if(highest<a)
highest=a;
all+=a;
broiflowers--;
}
cin>>needed;
kapki*=highest;
kapki-=all;
kapki*=needed;
cout<<kapki;
}
