#include<iostream>
using namespace std;
int main(){
long long c,n;
bool delilisenavs=0;
cin>>n;
long long i,chisla[n];
for(i=0;i<n;i++){
  cin>>chisla[i];
}
for(c=1;!delilisenavs;c++){
   for(i=0;i<n;i++){
      if(c*c%chisla[i]!=0){
          delilisenavs=0;
          break;
      }else{
          delilisenavs=1;
      }
   }
}
cout<<c-1;
return 0;
}
