#include<iostream>
using namespace std;
int main (){
    long long n,i,doIndex,brA,brB,brC,brD,longestP=0;
    cin>>n;
    char vhod[n];
    cin>>vhod;
    for(doIndex=0;doIndex<n;doIndex=doIndex+1){
        brA=0;
        brB=0;
        brC=0;
        brD=0;
        for(i=0;i<=doIndex;i=i+1){
            if(vhod[i]=='a'){
                brA=brA+1;
            }
            if(vhod[i]=='b'){
                brB=brB+1;
            }
            if(vhod[i]=='c'){
                brC=brC+1;
            }
            if(vhod[i]=='d'){
                brD=brD+1;
            }
        }
        if(brA+brB==brC+brD){
            longestP=doIndex;
        }
    }
    if(longestP!=0){
        cout<<longestP+1;
    }else{
        cout<<"0";
    }
    return 0;
}
