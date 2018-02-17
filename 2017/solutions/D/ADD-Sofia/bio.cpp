#include<iostream>
using namespace std;
int main(){
int meseci[]={31,28,31,30,31,30,31,31,30,31,30,31};
int sb[4];
char c;
for(int i=0;i<4;i++){
  int a,b;
  cin>>b;
  cin>>c;
  cin>>a;
  sb[i]=b;
  for(int j=0;j<a-1;j++){
    sb[i]+=meseci[j];
  }
}
for(int i=0;i<1000;i++){
  if((sb[0]+23*i-sb[1])%28==0 && (sb[0]+23*i-sb[2])%33==0 && i>0){
    cout<<"bravo"<<sb[0]+23*i-sb[0]+(sb[3]-sb[0]);
    return 0;
  }
}
}

