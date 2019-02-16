#include<iostream>
using namespace std;
int main(){
long long a,b,m,g,j=3,br=0;
cin>>a>>b;
if(a>b){
    m=b;
    g=a;
}else{
    m=a;
    g=b;
}
for(long long k=1;k<=m;k+=j){
    j+=2;
}
for(long long i=m;i<=g;i+=j){
    j+=2;
    br++;
}
cout<<br;
return 0;
}
