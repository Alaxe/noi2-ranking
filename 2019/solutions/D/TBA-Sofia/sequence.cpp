#include<iostream>
using namespace std;
int main(){
    bool neshto=true;
    int doChislo,brChisla=4;
    while(neshto){
            if(brChisla==1){
                cout<<1;
            }else{
    for(int a=1;a<=(brChisla-1)/2;a++){
        cout<<a;
    }
    cout<<(brChisla-1)/2+1;
    for(int a=(brChisla-1)/2;a>=1;a--){
        cout<<a;
    }
            }
    brChisla++;
    }
    return 0;
}
