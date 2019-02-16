#include<bits/stdc++.h>
using namespace std;
int arr[10000];
bool tochenkoren(int ch){
    for(int i=1;true;i++){
        if(i*i==ch){
            return true;
        }
        if(i*i>ch){
            return false;
        }
    }
}
bool delilise(int chislo,int sz){
    for(int i=0;i<sz;i++){
        if(chislo%arr[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    bool Nok=false;
    int n,ng=0,skolkouvel;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>ng){
            ng=arr[i];
        }
    }
    int j=ng;
    skolkouvel=ng;
    while(true){
        if(!Nok){
            if(delilise(j,n)){
                Nok=true;
                skolkouvel=j;
            }
        }
        if(tochenkoren(j) && Nok){
            cout<<sqrt(j)<<endl;
            return 0;
        }
        j+=skolkouvel;
    }
    return 0;
}
