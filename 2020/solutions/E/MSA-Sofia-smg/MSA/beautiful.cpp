#include<iostream>
using namespace std;
int main(){
long long n,a,kopieNaA,br=0,b[19],i=0,kopieNaI;
cin>>n;
bool ravniLiSa=true;
for(a=1;a<=n;a=a+1){
    if(a>0 && a<10){
        br=br+1;
    }else{
        kopieNaA=a;
        while(kopieNaA>0){
            b[i]=kopieNaA%10;
            i=i+1;
            kopieNaA=kopieNaA/10;
        }
        while(i>=0){
            if(b[i]==b[i-1]){
                ravniLiSa=true;
            }else{
                ravniLiSa=false;
            }
            i=i-1;
        }
        if(ravniLiSa){
            br=br+1;
        }
    }
}
cout<<br;

    return 0;
}
