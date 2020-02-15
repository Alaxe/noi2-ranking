#include<iostream>
 using namespace std;
 int main(){
 long long n,x,l=0,c=1,d=2,e;
  cin>>n>>x;
  for(int i=1;i<=n;i++){
    if(i%2==1){
      if(l>c){
        l=l+c;
        c=l-c;
        l=l-c;
      }
      else{
        c=c+l;
        l=c-l;
        c=c-l;

      }
    }
    if(i%2==0){
      if(d>c){
        d=d+c;
        c=d-c;
        d=d-c;
      }
      else{
        c=c+d;
        d=c-d;
        c=c-d;

      }
    }
  }
  if(x==0){
    cout<<l;

  }
  if(x==1){
    cout<<c;

  }
  if(x==2){
    cout<<d;

  }
 }
