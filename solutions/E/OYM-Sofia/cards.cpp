#include<iostream>
using namespace std;
int main(){
long long a,broiach=0,rezultat=0;
cin>>a;
long long b[a*2];
for(int c=0;c<a*2;c++){
    cin>>b[c];
}
for(int c=0;c<a*2-3;c=c+2){
    if(b[c]>=b[c+2] and b[c+1]>=b[c+3] or b[c]>=b[c+3] and b[c+1]>=b[c+2]){
        broiach++;
        if(broiach>rezultat){
            rezultat=broiach;
        }
    }else{
        broiach=1;
    }
}
cout<<rezultat;
return 0;
}
