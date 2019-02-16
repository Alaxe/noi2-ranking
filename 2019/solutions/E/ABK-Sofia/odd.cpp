#include<iostream>
using namespace std;
int main(){
long long chislo1,chislo2,delitel=0,chisla=0;
cin>>chislo1>>chislo2;
for(long long i=chislo1;i<=chislo2;i++){
    for(long long i2=1;i2<=i;i2++){
        if(i%i2==0){
         delitel++;
        }
    }
    if(delitel%2==1){
chisla++;
    }
    delitel=0;
}
cout<<chisla;

return 0;
}


