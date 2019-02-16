#include<iostream>
using namespace std;
long long a[10001];
long long nok=1;
long long nod(long long a,long long b){
     if(a==0){
        return b;
     }
     return nod(b%a,a);
}
int main(){
long long n,chislo=1;
cin>>n;
for(long long no=0;no<n;no++){
   cin>>a[no];
    if(nok<a[no]){
       nok=nod(nok,a[no])*nok/nod(nok,a[no])*a[no]/nod(nok,a[no]);
    }else{
nok=nod(a[no],nok)*nok/nod(a[no],nok)*a[no]/nod(a[no],nok);
    }
}
for(long long i=2;i*i<=nok;i++){
  long long broi=0;
  if(nok%i==0){

    while(nok%i==0){
        nok/=i;
       broi++;
    }
  }if(broi%2==0){
    for(long long g=0;g<(broi)/2;g++){
        chislo*=i;
     }
  }else{
     for(long long g=0;g<(broi+1)/2;g++){
        chislo*=i;
     }
  }

}if(nok>0){
 chislo*=nok;
}
cout<<chislo;
return 0;
}
