#include<iostream>
using namespace std;
int main (){
long long m,k,x=0,i=0,chislo[7],a=0,b=0;
cin>>m>>k;
while(k>x){
  cin>>chislo[i];
  if(chislo[i]%2==0){
    x=x+chislo[i];
  }
i=i+1;
}
while(i>=0){
if(chislo[i]>m){
while(chislo[i]!=m+a){
  a=a+1;
}
if(chislo[i]==m+a){
  cout<<i;
}
}
if(chislo[i]<m){
while(chislo[i]!=m-b){
  b=b+1;
}
if(chislo[i]==m-a){
  cout<<i;
}
}
}

return 0;
}
