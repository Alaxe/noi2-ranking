#include<iostream>
using namespace std;
long long int mirror(long long int a){
  long long int b=0;
  while(a){
    b*=10;
    b+=a%10;
    a/=10;
    }
  return b;
  }
int main(){

long long int n,i,j,c1,c2,ng=-1;
cin>>n;
for(i=1;i<n;i++){
  for(j=1;j<n;j++){
    if(mirror(i*j)==i*j){
      if(mirror(i*j)>ng){ng=i*j;c1=i;c2=j;}
      }
    }
  }
cout<<c1<<" "<<c2<<endl<<ng<<endl;

return 0;
}
