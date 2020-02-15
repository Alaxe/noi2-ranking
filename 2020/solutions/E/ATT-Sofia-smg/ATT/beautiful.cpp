#include<iostream>
using namespace std;
int main(){
long long N, i, br=0;
cin>>N;
if(N==1){
            br=br+1;
        }
        if(N==2){
            br=br+2;
        }
        if(N==3){
            br=br+3;
        }
        if(N==4){
            br=br+4;
        }
        if(N==5){
            br=br+5;
        }
        if(N==6){
            br=br+6;
        }
        if(N==7){
            br=br+7;
        }
        if(N==8){
            br=br+8;
        }
        if(N>=9){
            br=br+9;
        }
for(i=1;i<=N;i=i+1){
    if(i%10==(i/10)%10){
            br=br+1;
        }
    }
cout<<br;
return 0;
}
