#include<iostream>
using namespace std;
int main (){
long long n,k,chiclo=1,h,l=0;
bool NeotkriKrasivo=true;
cin>>n>>k;
while(n>1){
chiclo=chiclo*10;
n=n-1;
}
h=chiclo*10;
for(chiclo=chiclo;NeotkriKrasivo;chiclo++){
if(h==chiclo){
l=1;
break;
}
if(chiclo%k==0){
NeotkriKrasivo=false;
break;
}
}
if(l==0){
cout<<chiclo;
}
else{
cout<<"NO";
}
return 0;
}
