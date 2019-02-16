#include<bits/stdc++.h>
using namespace std;
long long pr[14]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
long long brsr[44],brizp[44];
long long ch[10000];
long long stepen(long long osn,long long pok) {
if (pok==0) return 1;
if (pok%2==0) {
   long long  i=stepen(osn,pok/2);
    return i*i;
}
else return stepen(osn,pok-1)*osn;
}
long long razl(long long c) {
    long long st;
for (int q=0;c>1;q++) {
     st=0;
    while (c%pr[q]==0) {
        st++;
        c=c/pr[q];
    }
  st=(st+1)/2;
  if (st>brsr[pr[q]]) brsr[pr[q]]=st;
}
}
int main () {
long long n,otg=1;
cin>>n;
for (int q=0;q<n;q++) cin>>ch[q];
for (int q=0;q<n;q++) {
      if (brizp[ch[q]]==0){
        razl(ch[q]);
       brizp[ch[q]]++;
      }
}
for (int q=0;q<14;q++) otg=otg*stepen(pr[q],brsr[pr[q]]);
cout<<otg;
}
