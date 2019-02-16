#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin>>n>>k;
    long long nn=2*(n-1)*(n-1)/2, kk;
    if(k%2==0)kk=(2*n-1+(n+k-3))*k/4+n*n-1; else kk=(2*n-1+n+2*(k-1))*((k-1)/2+1)/2-n+1;
    cout<<nn+kk<<endl;
    main();
    return 0;
}
