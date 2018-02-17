#include <iostream>
using namespace std;
int main(){
long long n,k,chislo;
cin>>n>>k;
if(n==1){
if(k>9){
    cout<<"NO";
    return 0;
}else{
cout<<k;
return 0;
}
}
if(n==2){
        if(k>99){
            cout<<"NO";
            return 0;
        }else{
  for(int h=10;h<100;h++){
    if(h%k==0){
        cout<<h;
        return 0;
    }
  }
}
}
if(n==3){
if(k>999){
    cout<<"NO";
    return 0;
}else{
for(int p=100;p<1000;p++){
    if(p%k==0){
        cout<<p;
        return 0;
    }
}
}
}
if(n==4){
    if(k>9999){
        cout<<"NO";
        return 0;
    }else{
    for(long f=1000;f<10000;f++){
        if(f%k==0){
            cout<<f;
            return 0;
        }
    }
    }
}
if(n==5){
    if(k>99999){
        cout<<"NO";
        return 0;
    }else{
    for(long long o=10000;o<100000;o++){
        if(o%k==0){
            cout<<o;
            return 0;
        }
    }
    }
}
if(n==6){
    if(k>999999){
        cout<<"NO";
        return 0;
    }else{
    for(long long i=100000;i<1000000;i++){
        if(i%k==0){
            cout<<i;
            return 0;
        }
    }
    }
}
if(n==7){
    if(k>9999999){
        cout<<"NO";
        return 0;
    }else{
    for(long long t=1000000;t<10000000;t++){
        if(t%k==0){
            cout<<t;
            return 0;
        }
    }
    }
}
if(n==8){
    for(long long q=10000000;q<100000000;q++){
        if(q%k==0){
            cout<<q;
            return 0;
        }
    }
}
if(n==9){
    for(long long w=100000000;w<1000000000;w++){
        if(w%k==0){
            cout<<w;
            return 0;
        }
    }
}
if(n==10){
    for(long long e=1000000000;e<10000000000;e++){
        if(e%k==0){
            cout<<e;
            return 0;
        }
    }
}
if(n==11){
    for(long long y=10000000000;y<100000000000;y++){
        if(y%k==0){
            cout<<y;
            return 0;
        }
    }
}
if(n==12){
    for(long long u=100000000000;u<1000000000000;u++){
        if(u%k==0){
            cout<<u;
            return 0;
        }
    }
}
if(n==13){
    for(long long a=1000000000000;a<10000000000000;a++){
        if(a%k==0){
            cout<<a;
            return 0;
        }
    }
}
if(n==14){
    for(long long s=10000000000000;s<1000000000000000;s++){
        if(s%k==0){
            cout<<s;
            return 0;
        }
    }
}
if(n==15){
    for(long long d=100000000000000;d<1000000000000000;d++){
        if(d%k==0){
            cout<<d;
            return 0;
        }
    }
}
if(n==16){
    for(long long g=1000000000000000;g<10000000000000000;g++){
        if(g%k==0){
            cout<<g;
            return 0;
        }
    }
}
if(n==17){
    for(long long j=10000000000000000;j<100000000000000000;j++){
        if(j%k==0){
            cout<<j;
            return 0;
        }
    }
}
if(n==18){
    for(long long l=100000000000000000;l<1000000000000000000;l++){
        if(l%k==0){
            cout<<l;
            return 0;
        }
    }
}
return 0;
}
