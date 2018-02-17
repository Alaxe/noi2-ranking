#include<iostream>
using namespace std;
int main(){
    int N;
    int rezultat;
    cin>>N;
    int chislo[N];
    int bez_nula=N;
    int proba[429496729];
    int proba_counter=0;
    for(int a=0; a<N;a++){
        cin>>chislo[a];
        if(chislo[a==0]){
            bez_nula--;
        }
    }
    for(int b;b<N;b++){
    //dvoiki
    proba[proba_counter]=chislo[b]+chislo[b];
    proba_counter++;
    }
    return 0;
}
