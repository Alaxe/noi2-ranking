#include<bits/stdc++.h>
using namespace std;
bool razdeliliLiSmeNa[100];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
unsigned long long x=1;
for(int i=1;i<=k-1;i++){
    razdeliliLiSmeNa[i]=0;
}
    for(int i=n-k+1;i<=n-1;i++){
        x=x*i;
        for(int j=1;j<=k-1;j++){
            if(x%j==0 && razdeliliLiSmeNa[j]==0){
                x=x/j;
                razdeliliLiSmeNa[j]=1;
            }
        }
    }
cout<<x;
/*
int a,b;
cin>>a>>b;
while(a!=0 and b!=0){
   if(a>b){
    a=a%b;
   }else{
    b=b%a;
   }
}
cout<<max(a,b);
*/
return 0;
}
