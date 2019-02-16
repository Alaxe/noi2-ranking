#include <bits/stdc++.h>
using namespace std;

long long year[33][14][402],month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
long long d,m,y,sum=1,naum,now=0,ND,NM,NY,br,nowY,newDate,today,sedmici;
char znak;

for (int y=1;y<=400;y++){
    for(int m=1;m<=12;m++){
            naum=0;
        if(!(y%4==0 && y%100!=0 || y%400==0)){
           naum++;
        }
        if(m==2){
          for(int d=1;d<=(month[m]-naum);d++){
            now++;
            year[d][m][y]=now;
        }
        }else{
        for(int d=1;d<=month[m];d++){
            now++;
            year[d][m][y]=now;
        }
        }
    }
}
cin>>ND>>znak>>NM>>znak>>NY>>br;

nowY=NY%400;
newDate=year[ND][NM][nowY];
today=newDate%7;

if(today==6 || today==0){
    if(today==6){
        newDate++;
    }
br++;
}else{
if((5-today)>br){
newDate+=br%5;
br=0;
}else{
br=br-(5-today);
int zdr=0;
if(today==0){
   zdr=7;
}
newDate=newDate+7-today-zdr;
}
}

newDate+=br/5*7;
newDate+=br%5;
if(br%5==0 &&  br>0){
    newDate-=2;
}


now=0;
bool krai=false;
for (int y=1;y<=400 &&  krai==false;y++){
    for(int m=1;m<=12 &&  krai==false;m++){
            naum=0;
        if(!(y%4==0 && y%100!=0 || y%400==0)){
           naum++;
        }
        if(m==2){
          for(int d=1;d<=(month[m]-naum) &&  krai==false;d++){
            now++;
            if(now==newDate){
                krai=true;
                y=y+NY/400*400;
                if(d<10){
                    cout<<"0";
                }
                cout <<d<<".";
                if(m<10){
                    cout<<"0";
                }
                cout<<m<<"."<<y<<endl;
            }
        }
        }else{
        for(int d=1;d<=month[m] &&  krai==false;d++){
            now++;
            if(now==newDate){
                krai=true;
                y=y+NY/400*400;
                if(d<10){
                    cout<<"0";
                }
                cout <<d<<".";
                if(m<10){
                    cout<<"0";
                }
                cout<<m<<"."<<y<<endl;
            }
        }
        }
    }
}

return 0;
}
