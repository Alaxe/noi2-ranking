#include<iostream>
using namespace std;
int main(){

long long int ng=-1,po=0,n,i,a1,b1,a2=-1,b2=-1;
cin>>n;
for(i=0;i<n;i++){
  cin>>a1>>b1;
  if(a1>b1)swap(a1,b1);
  if(a1<=a2 && b1<=b2)po++;
  else {
    if(po>ng){
      ng=po;
      }
    po=1;
    }
  a2=a1;
  b2=b1;
  }
if(po>ng)ng=po;
cout<<ng<<endl;

return 0;
}
