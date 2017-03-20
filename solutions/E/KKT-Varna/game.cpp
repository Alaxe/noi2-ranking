#include<iostream>
using namespace std;
int main(){

long long int s=0,nor,no=999999999,a,kl,i,b,n,k;
cin>>a>>b;
for(i=0;i<200;i++){
  cin>>k;
  if(k%2==0)s+=k;
  if(a>k)kl=a-k;
  else kl=k-a;
  if(kl<=no){
    if(kl==no && k<a){no=kl;nor=i+1;}
    else if(kl<no){no=kl;nor=i+1;}
    }
  if(s>b)break;
  }
cout<<nor<<" "<<s<<endl;

return 0;
}
