#include<bits/stdc++.h>
using namespace std;
long long f[300][300];
long long nameri(long long n,long long m){
    if(n<0)return 0;

if(f[n][m]!=-1)return f[n][m];

long long a=0;
a=min(n,m);
for(int i=1;i<=a;i++){
        if(i==1){
    f[n][m]=nameri(n-i,i);
        }else{
        f[n][m]+=nameri(n-i,i);
        }
}
return f[n][m];
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
long long n,m,otg=0;
cin>>n>>m;
for(int i=0;i<300;i++){
    for(int j=0;j<300;j++){
            if(i==0){
             f[i][j]=1;
            }else{
            f[i][j]=-1;
            }
    }
}

otg=nameri(n,m);
cout<<otg<<"\n";
return 0;
}
