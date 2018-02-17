#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
int n, sbor=0;
cin>>n;
long long nfact=1;
for(int i=2; i<=n; i++){
    nfact=nfact*i;
    if(nfact%10==0){
        nfact=nfact/10;
    }
}
while(nfact>0){
    sbor=sbor+nfact%10;
    nfact=nfact/10;
}
cout<<sbor<<endl;
return 0;
}
