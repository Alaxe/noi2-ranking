#include<iostream>
using namespace std;
int main(){
long long n,m,x,y=1,z;
cin>>n>>m;
for(;n<=m;){
        z=n;
        x=0;
    for(int i=0;i<6;i++){
        x=x+(z%10);
        z=z/10;
    }
    n=n+x;
    if(n<=m){
        y++;
    }
}
cout<<y<<endl;
return 0;
}
