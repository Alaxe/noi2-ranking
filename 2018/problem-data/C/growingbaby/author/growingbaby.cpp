#include <cstdio>
unsigned A[8000]={1}, m,n,p,q,i,k,s,MOD=1<<30;
int main(){
  for (scanf(" %u %u %u %u", &m, &n, &p, &q), (n-m<p?n=0:n-=m+p), k=p-q; i<n; i++)
    (i+p<n?A[i+p]=A[i]:s=(s+A[i])%MOD), (i+k<n?A[i+k]=(A[i+k]+A[i])%MOD:s=(s+A[i])%MOD);
  printf("%u\n",s?s:1)-1;
}
