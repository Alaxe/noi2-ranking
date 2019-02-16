#include <bits/stdc++.h>
using namespace std;
int main(){
bool purvo=false;
long long n,k,redica,dob=1,ans=0;
cin>>n>>k;

if(k%2==0){
    k++;
    purvo=true;
}
redica=(k-1)/2+n-1;

for(int i=0;i<redica;i++){
    ans+=dob;
    dob+=2;
}

if(purvo==false){
ans+=2*redica+2-n;
}else{
ans+=n;
}
cout<<ans<<endl;

return 0;
}
