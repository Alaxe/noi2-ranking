#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,k,a=0,br1=1,br2=0;
cin>>n>>k;
while(a<k){
    br2=br1+br2;
    br1=br1+2;
    if(br1/2==n){
        a++;
    }
    if(br1/2>n){
        a=a+2;
    }
}
//
//cout<<br2<<" "<<br1<<endl;
if(a==k){
    cout<<br2-n+1;
}else{
    cout<<br2-br1+2 +n;
}
cout<<endl;
return 0;
}
