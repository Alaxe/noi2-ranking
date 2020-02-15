#include <iostream>
using namespace std;
int main(){
long long n,a,broia=0,broib=0,broic=0,broid=0,d=0;
cin>>n;

char b[n];

for(a=0;a<n;a++){
    cin>>b[a];
    if(b[a]=='a'){
       broia++;

    }
    if(b[a]=='b'){
        broib++;

    }
    if(b[a]=='c'){
        broic++;

    }
    if(b[a]=='d'){
        broid++;

    }
}


if(broia<=broib && broia<=broic && broia<=broid){
    d=broia*4;
}
if(broib<=broia && broib<=broic && broib<=broid){
    d=broib*4;
}
if(broid<=broia && broid<=broib && broid<=broic){
    d=broid*4;
}
if(broic<=broia && broic<=broib && broic<=broid){
    d=broic*4;
}
cout<<d;
}
