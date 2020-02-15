#include<iostream>
using namespace std;
long long c[3];
int main(){

unsigned long long a,b;
cin>>a>>b;
c[b]=1;
for(long long i=a;i>=1;i--){
    if(i%2==0){
        swap(c[2],c[1]);
    }else swap(c[0],c[1]);
}
for(int i=0;i<3;i++){
    if(c[i]==1){
        cout<<i<<endl;
    }
}

return 0;
}

