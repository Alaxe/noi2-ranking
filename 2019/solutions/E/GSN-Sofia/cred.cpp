#include<iostream>
using namespace std;
long long stepen(long long h , long long s){
long long proizv=1;
    for(long long i=0;i<s;i++){
        proizv=proizv*h;
    }
    return proizv;
}

long long cifri(long long g){
    long long br=0;
    bool yslovie=true;
    for(int i;yslovie;i++){
        g=g/10;
        br++;
        if(g<10){
            yslovie=false;
            return br+1;
        }
    }
}

long long d(long long n){
    long long a,cifri_sb=0;
    for(int i=cifri(n);i>0;i--){
        cifri_sb=cifri_sb+n/stepen(10,i-1)%10;
    }
    return n+cifri_sb;
}

int main(){

long long n,m,i,br=0;
cin>>n>>m;
for(i=n;i<=m;i=d(i)){
    br++;
}
cout<<br<<endl;

return 0;
}
