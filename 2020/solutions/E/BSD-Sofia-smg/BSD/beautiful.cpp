#include<iostream>
using namespace std;
int main (){
    long long n,page,poslednaCifraChislo,beautifulP=0,
    chisloRaz;
    bool ednakviCifri=true,canContinue;
    cin>>n;
    for(page=1;page<=n;page=page+1){
        ednakviCifri=true;
        canContinue=true;
        chisloRaz=page;
        while(chisloRaz>0 && canContinue){
            poslednaCifraChislo=chisloRaz%10;
            if(chisloRaz/10>0){
                chisloRaz=chisloRaz/10;
                if(chisloRaz%10 != poslednaCifraChislo){
                    ednakviCifri=false;
                }
            }else{
                canContinue=false;
            }
        }
        if(ednakviCifri){
           beautifulP=beautifulP+1;
        }
    }
    cout<<beautifulP;
    return 0;
}
