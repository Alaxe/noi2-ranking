#include<iostream>
#include<cstring>
using namespace std;
int main (){
char vhod[160001];
cin>>vhod;
long long i=0,dulj,j,brcif=1,brchsla=3,n=0,mnoj=1;
dulj=strlen(vhod);
while(brcif<=4 and i<dulj){
    if(brcif%4==0){
        i=i+brcif*4;
    }else{
        i=i+brcif*3;
    }
    brcif++;
}
while(i<dulj){
    if(brcif%3==0){
        i=i+brcif*4;
    }else{
        i=i+brcif*3;
    }
    brcif++;
}
brcif=brcif-1;
for(i=dulj-1; i>=dulj-brcif; i--){
    n=n+vhod[i]*mnoj-48*mnoj;
   // cout<<"mnoj - "<<mnoj<<"vhod[i] - "<<vhod[i]<<" n -> "<<n<<endl;
    mnoj=mnoj*10;
}
long long cn=n,br=0;
while(cn>1){
    cn=cn/2;
    br++;
}
cout<<br<<endl;
return 0;
}
