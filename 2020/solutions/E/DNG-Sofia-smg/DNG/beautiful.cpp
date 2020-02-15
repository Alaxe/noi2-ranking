#include<iostream>
using namespace std;
int main(){
    long long N,br=0;
    cin>>N;
    long long chislo=1,x=1;
    long long chisloCopy;
    while(chislo<=N){
        chisloCopy=0;
        if(chislo%10!=9){
            while(chislo!=0){
                chisloCopy+=(chislo%10+1)*x;
                x*=10;
                chislo/=10;
            }
            chislo=chisloCopy;
        }
        else{
            while(chislo!=0){
                chisloCopy+=(chislo%10-8)*x;
                x*=10;
                chislo/=10;
            }
            chisloCopy+=x;
            chislo=chisloCopy;
        }
        x=1;
        br++;
    }
    cout<<br;
return 0;}
