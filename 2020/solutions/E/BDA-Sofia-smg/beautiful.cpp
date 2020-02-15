#include<iostream>
using namespace std;
int main(){
long long n,krasivi=0,brEdnakviCifri=0,gledano,gledano2,cifriNaChislo[19],brCifri=0;
cin>>n;
if(n<=9){
    cout<<n<<endl;
}else{
    if(n>9){
        krasivi=9;
        for(gledano=10;gledano<=n;gledano=gledano+1){
            gledano2=gledano;
            for(brCifri=0;gledano2>0;brCifri=brCifri+1){
                cifriNaChislo[brCifri]=gledano2%10;
                gledano2=gledano2/10;
            }
            if(brCifri%2==0){
                for(int i=0;i<=brCifri;i=i+1){
                    if(cifriNaChislo[brCifri/2]==cifriNaChislo[i]){
                        brEdnakviCifri++;
                    }
                }
                if(brEdnakviCifri==brCifri){
                    krasivi=krasivi+1;
                }
                brEdnakviCifri=0;
                brCifri=0;
            }else{
                for(int i=0;i<=brCifri;i++){
                    if(cifriNaChislo[0]==cifriNaChislo[i]){
                        brEdnakviCifri++;
                    }
                }
                if(brEdnakviCifri==brCifri){
                    krasivi=krasivi+1;
                }
                brEdnakviCifri=0;
                brCifri=0;
            }
        }
    }
}
cout<<krasivi<<endl;
return 0;
}
