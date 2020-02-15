#include<iostream>
using namespace std;
char a[100000];
int main(){
long long n,gledanznak,brA=0,brB=0,brC=0,brD=0;
cin>>n;
cin>>a;
for(gledanznak=0;a[gledanznak]!='\0';gledanznak++){
      if(a[gledanznak]=='a'){
        brA++;
      }else{
          if(a[gledanznak]=='b'){
            brB++;
          }else{
              if(a[gledanznak]=='c'){
                brC++;
              }else{
                  if(a[gledanznak]=='d'){
                    brD++;
                  }
              }
          }
      }
}
if(brA+brB==brC+brD){
    cout<<n<<endl;
}else{
    if(brA+brB>brC+brD && brC+brD>1){
        n=n-(brA+brB-brC-brD);
        cout<<n<<endl;
    }else{
        if(brC+brD<=1){
            cout<<0<<endl;
            return 0;
        }
    }
        if(brA+brB<brC+brD && brA+brB>1){
            n=n-(brC+brD-brA-brB);
            cout<<n<<endl;
        }else{
            if(brA+brB<=1){
               cout<<0<<endl;
               return 0;
            }
        }
    }
return 0;
}
