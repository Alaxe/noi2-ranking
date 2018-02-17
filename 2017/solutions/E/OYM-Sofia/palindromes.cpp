#include<iostream>
using namespace std;
int main(){
long long a,palindrom=0,probno,izvedeno1=0,izvedeno2=0,n=0,sbor;
cin>>a;
for(int b=1;b<a;b++){
    for(int c=1;c<a;c++){
        if(b*c>palindrom){
            probno=b*c;
            while(probno>0){
                n++;
                probno=probno/10;
            }
            if(n==1){
                palindrom=b*c;
                izvedeno1=b;
                izvedeno2=c;
            }
            if(n==2){
                if((b*c)%11==0){
                    palindrom=b*c;
                    izvedeno1=b;
                    izvedeno2=c;
                }
            }
            if(n==3){
                if((b*c)%10==b*c-((b*c)%100)/100){
                    palindrom=b*c;
                    izvedeno1=b;
                    izvedeno2=c;
                }
            }
        }
    }
}
cout<<izvedeno1<<" "<<izvedeno2<<"\n"<<palindrom;
return 0;
}

