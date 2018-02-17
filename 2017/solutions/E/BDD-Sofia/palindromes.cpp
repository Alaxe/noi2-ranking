#include<iostream>
using namespace std;
long long a,b,broi,s,maxDosega,broi2;

int main (){
    long long n,cifri[9],k,chislo,pyrvo=0,vtoro=0;
    cin>>n;
    for(a=1;a<n/2+1;a++){
        for(b=n/2+1;b>0;b--){
            chislo=a*b;
            k=chislo;
            while(k!=0){
                cifri[broi]=k%10;
                k=k/10;
                broi++;
            }
            while(s<broi/2){
                if(cifri[s]==cifri[broi-s-1]){
                    broi2++;
                }
                s++;
            }
            cout<<"OK";
            if(broi2==broi/2){
                if(maxDosega<chislo){
                    maxDosega=chislo;
                    pyrvo=a;
                    vtoro=b;
                }
            }
        }
    }
cout<<maxDosega<<" "<<pyrvo<<" "<<vtoro;
return 0;
}
