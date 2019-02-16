#include<bits/stdc++.h>
using namespace std;

bool used[64];
int dels[13],primes[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};

void filldels(int x){
  if(x==1)return ;
  int i=0;
  while(x>1){
    if(x%primes[i]==0){++dels[i];x/=primes[i];}
    else ++i;
    }
  }

int main(){

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);

int n,k,x;
scanf("%d %d",&n,&k);

for(int i=0;i<n;++i){
  scanf("%d",&x);
  if(!used[x]){
    filldels(x);
    used[x]=1;
    }
  }

unsigned long long res=1;

for(int i=0;i<13;++i){
  if(dels[i]){
    if(dels[i]>=k)res*=(dels[i]/k)*primes[i];
    if(dels[i]%k!=0)res*=primes[i];
    }
  }

cout<<res<<"\n";

return 0;
}
/*
4 3
3 4 5 6
*/
