#include<iostream>
using namespace std;
int main(){
long long a;
cin>>a;
char b[a*a][2];
long long c[a][a];
for(int i=0;i<a*a;i++){
    for(int j=0;j<2;j++){
        cin>>b[i][j];
    }
}
for(int i=0;i<a*a;i++){
    if(1<b[i][0]<10){
        c[i/a][i%a]=b[i][0]-'0';
    }
}
for(int i=0;i<a*a;i++){
    if(b[i][0]=='A'){
        c[i/a][i%a]=b[i][0]+'B'-'A'-'A';
    }
}
for(int i=0;i<a*a;i++){
    if(b[i][0]=='T'){
        c[i/a][i%a]=b[i][0]-'J';
    }
}
for(int i=0;i<a*a;i++){
    if(b[i][0]=='J'){
        c[i/a][i%a]='U'-'J';
    }
}
for(int i=0;i<a*a;i++){
    if(b[i][0]=='Q'){
        c[i/a][i%a]='V'-'J';
    }
}
for(int i=0;i<a*a;i++){
    if(b[i][0]=='K'){
        c[i/a][i%a]='W'-'J';
    }
}
long long sbor=c[a-1][0],one=a-1,two=0;
while(true){
    if(c[one-1][two]<=c[one][two+1] and two!=a-1){
        sbor+=c[one][two+1];
        two+=1;
    }else{
        sbor+=c[one-1][two];
        one-=1;
    }
    if(one==0 and two==a-1){
        break;
    }
}
cout<<sbor;
return 0;
}

