#include<iostream>
using namespace std;
int main(){
long long n,brA=0,brB=0,brC=0,brD=0,obA=0,obD=0;
char a[1000000];
cin>>n>>a;
for(int i=0;i<n;i++){
    if(a[i]=='a'){
        brA++;
    }else{
        if(a[i]=='b'){
            brB++;
        }else{
            if(a[i]=='c'){
                brC++;
            }else{
                if(a[i]=='d'){
                    brD++;
                }
            }
        }
    }
}
obA=brA+brB;
obD=brC+brD;
if(brA+brB>brC+brD){
    while(!obA==obD){
        obA=obA-1;
    }
}else{
    if(brA+brB<brC+brD){
        while(!obA==obD){
            obD=obD-1;
        }
    }
}
cout<<obA*2;


    return 0;
}
