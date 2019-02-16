#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
long long a[51][51],k,m,n,i,j,ans;
int main(){
cin>>k>>m>>n;
for(i=1;i<=n;i++){
        for(j=1;j<m;j++){
            if(i==1)a[i][j]=1;
            else{
                //cout<<j<<" "<<j-k<<" "<<j+k<<endl;
                if(j-k>0)a[i][j]+=a[i-1][j-k];
                if(j+k<m)a[i][j]+=a[i-1][j+k];
            }
        }
        /*for(j=1;j<m;j++)cout<<a[i][j]<<" ";
        cout<<endl;*/
}
for(i=1;i<m;i++)ans+=a[n][i];
cout<<ans<<endl;
return 0;
}
