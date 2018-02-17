#include<iostream>
using namespace std;

int A[10000009];
int fmax(int i, int k) {
  int m=0;
  for(int j= i-k+1<0?0:i-k+1 ; j<=i; j++) {
    m=max(A[j],m);
  }
  return m;
}
int main() {
  long long k,n,f,m,a,mod;
  cin>>n>>k>>f>>m>>a>>mod;
  A[0]=f;
  long long res=f;
  if(k>=n) {
    for(int i=1; i<n; i++) {
      A[i] = (A[i-1]*m+a)%mod;
      //if(A[i-1]<A[i]){res+=A[i];}
      //else
      //{
      long long a=max(A[i],A[i-1]);
      res+=a;
      //}
      //cout<<fmax(i,k)<<endl;
    }
  }else{
  long long last=0;
  for(int i=1; i<n; i++) {
    A[i] = (A[i-1]*m+a)%mod;
    if(A[i]>=last){last=A[i];res+=A[i];continue;}
    //if(A[i-1]<A[i]){res+=A[i];}
    //else
    //{
    long long a=fmax(i,k);
    res+=a;
    last = a;

    //}
    //cout<<fmax(i,k)<<endl;
  }
  }
  cout<<res<<endl;
  return 0;
}
