#include <iostream>
#include <cstring>
using namespace std;
int main(){

char stepeni[160001];
cin>>stepeni;
long long nKoqStepen=1,gledano,dobavqme=1,putidobaveno=0,n=3;

for(gledano=0;gledano<strlen(stepeni);gledano=gledano+dobavqme)
    {if(nKoqStepen>3 and nKoqStepen<7){dobavqme=2;}
    else{if(nKoqStepen>0 and nKoqStepen<4){dobavqme=1;}
            if(nKoqStepen>6 and nKoqStepen<10){dobavqme=3;}
    else {if(nKoqStepen>9 and nKoqStepen<14){dobavqme=4;}
    if(putidobaveno<n)
        {putidobaveno++;}
    else{if(n==3){n=4;putidobaveno=0;dobavqme=4;}else {dobavqme=dobavqme+1;putidobaveno=0;}
     }
    }}
      nKoqStepen=nKoqStepen+1;}
if(dobavqme>4){cout<<nKoqStepen-(dobavqme-4+1);return 0;}
  cout<<nKoqStepen-1;
return 0;}
