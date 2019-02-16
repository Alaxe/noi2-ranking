#include<iostream>
using namespace std;
int main(){
long long a,b,x,y,z=0,i;
cin>>a>>b;
for(i=a;i<=b;i++){
    x=1;
    y=0;
    for(;x<=i;x++){
        if(0==i%x){
            y++;
        }
    }
    if(1==y%2){
        z++;
    }
}
cout<<z<<endl;
return 0;
}
