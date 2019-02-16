#include<iostream>
using namespace std;
long long a,b,i,br,c=1;
int main(){
cin>>a>>b;
br=0;
for(i=3;i<=1000000000000000;i=i+2){
    if(a<=c && c<=b) br++;
    if(c>b) break;
    c=c+i;
}
cout<<br;

return 0;
}
