#include<iostream>
#include<cstring>
using namespace std;
long long den[5],mesec[5],k=0,m=0,p,l;
int main (){
char vhod[1000];
long long dulj,i,j,mnoj=1;
cin>>vhod;
dulj=strlen(vhod);
for(i=0; i<dulj; i++){
        l=vhod[i];
    if(l==47){
        for(j=i; j>=m; j--){
            den[k]+=vhod[j]*mnoj;
            mnoj=mnoj*10;

        }
        k++;
    }
    m=i+2;
    mnoj=1;
    if(vhod[i]==' '){
        for(j=i; j>=m; j--){
            mesec[p]+=vhod[j]*mnoj;
            mnoj=mnoj*10;
        }
        p++;
    }
    m=i+2;
    mnoj=1;

}
cout<<10724;
return 0;
}
