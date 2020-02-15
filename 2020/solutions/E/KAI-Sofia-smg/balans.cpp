#include <iostream>
using namespace std;
int main(){
    int brTopki,brAIB=0,brCID=0,naiMalkoVuzmojno=0;
    char cvqtTopka[101];
    cin>>brTopki;
    cin>>cvqtTopka;
    for(int i=0;i<brTopki;i++){
        if(cvqtTopka[i]=='a' || cvqtTopka[i]=='b'){
            brAIB++;
        }else{
            brCID++;
        }
        if(brAIB==brCID){
            naiMalkoVuzmojno=i+1;
        }
    }
    cout<<naiMalkoVuzmojno;
    return 0;
}
