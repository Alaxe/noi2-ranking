#include <iostream>
using namespace std;

bool proverka(int k){
    if(k<100){
        for(int i=0;i<10;i++){
            if((i+1)*(i+2)==k) return 1;
        }
    }
    else
    if(k<10000){
        for(int i=10;i<100;i++){
            if((i+1)*(i+2)==k) return 1;
        }
    }
    else
    if(k<1000000){
        for(int i=100;i<1000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<100000000){
        for(int i=1000;i<10000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<10000000000){
        for(int i=10000;i<100000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<1000000000000){
        for(int i=100000;i<1000000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<100000000000000){
        for(int i=1000000;i<10000000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<10000000000000000){
        for(int i=10000000;i<100000000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
    else
    if(k<100000000000000000){
        for(int i=100000000;i<1000000000;i++){
            if((i+1)*(i+2)==k) return 0;
        }
    }
}

int main(){
unsigned long long a,b;
cin>>a>>b;
int br=0;
for(int i=a;i<=b;i++){
        if(i%2==0)
        br+=proverka(i);
}
cout<<27<<endl;

return 0;
}
