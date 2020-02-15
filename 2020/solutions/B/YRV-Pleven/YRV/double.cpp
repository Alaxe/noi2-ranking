#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
using namespace std;
long long a[201][201][201],b[201],n,w1,w2,i,j,k;
int main(){
cin>>n>>w1>>w2;
for(i=1;i<=n;i++)scanf("%lld",&b[i]);
for(k=1;k<=n;k++){
    for(i=1;i<=w1;i++){
        for(j=1;j<=w2;j++){
            if(b[k]>i && b[k]>j)continue;
            a[k][i][j]=max(a[k-1][i][j],max(a[k][i-1][j],a[k][i][j-1]));
            if(b[k]<=i)a[k][i][j]=max(a[k][i][j],a[k-1][i-b[k]][j]+b[k]);
            if(b[k]<=j)a[k][i][j]=max(a[k][i][j],a[k-1][i][j-b[k]]+b[k]);
        }
    }
    //cout<<a[k][w1][w2]<<endl;
}
cout<<a[n][w1][w2]<<endl;
return 0;
}
