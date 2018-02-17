#include<iostream>
using namespace std;
int main () {
long long n,k,chislo=1,devet=9;
cin>>n;
cout<<" ";
cin>>k;
for(int i=0;i<n;i++){
     if(i!=0){
    chislo=chislo*10;
   devet=devet*10+9;
    }
 }
if(n>=2 && n<=1000 && k>=2 && k<=10000000 &&  k<chislo){
    for(int m=0;m<devet;m++){
        if(chislo%k!=0){
            chislo++;
        }else{
            break;
    }
}
}
cout<<chislo;
return 0;
}
