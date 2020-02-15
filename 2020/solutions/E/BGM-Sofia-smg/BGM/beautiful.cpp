#include<iostream>
using namespace std;
int main () {
long long n,kolko,i,f,m,g=0;
cin>>n;
for(i=n;i/10!=0;i=i/10){

}
f=i;
m=n%10;
if(f<=m){
   for(i=n;i/10!=0;i=i/10){
      g++;
}
kolko=g*9+f;
}
if(f>m){
   for(i=n;i/10!=0;i=i/10){
      g++;
}
kolko=g*9+f-1;
}
cout<<kolko;

return 0;
}
