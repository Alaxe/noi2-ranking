#include<iostream>
using namespace std;

int main(){

bool uslovie=true;
long long n,i,j,br=0;
cin>>n;
for(i=0;i<=1000000;i++){
    for(j=1;j<=i;j++){
        br++;
        if(n==j){
            cout<<br<<endl;
            return 0;
        }
    }
    for(j=i-1;j>0;j--){
        br++;
        if(n==j){
            cout<<br<<endl;
            return 0;
        }
    }
}

return 0;
}
