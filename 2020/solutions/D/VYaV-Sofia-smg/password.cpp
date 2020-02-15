#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[5001],smqna='a';
long long length,brSimvPored;
int main(){
cin>>a;
length=strlen(a);
for(int i=0;i<length;i++){
    brSimvPored=1;
    for(int j=i+1;brSimvPored!=3;j++){
        if(a[i]==a[j]){
            brSimvPored++;
        }else{
            break;
        }
    }
    if(brSimvPored>=3){
        if(a[i]!=smqna){
            a[i+brSimvPored/2]=smqna;
        }else{
            smqna++;
            a[i+brSimvPored/2]=smqna;
        }
        i+=2;
    }
}
cout<<a;
return 0;
}
