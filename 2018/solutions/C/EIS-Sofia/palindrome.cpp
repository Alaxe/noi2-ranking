#include<iostream>
#include<string>
using namespace std;
int main (){
long long n,a,brcifri=0,mnoj=1,i,cifri[10000],k;
cin>>n;
a=n;
while(a>0){
    brcifri++;
    i=i%10;
    a=a/10;
    mnoj=mnoj*10;
    cifri[brcifri-1]=i;
}
mnoj=mnoj/10;
a=n;
    /*if(a/mnoj>=a%10){
        a=a/10*10+a/mnoj;
    }else{
        a=a%mnoj+a%10*mnoj;
    }
    if(a/(mnoj/10)>=a/10-a/10*10){
        a=
    }*/
   /* k=brcifri/2;
    while(k>=0){
        if(cifri[0])

    }*/
    n=(a/mnoj+1)*mnoj+a/mnoj+1;
    cout<<n<<"\n";
return 0;
}
