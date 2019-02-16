#include <bits/stdc++.h>
using namespace std;

int k,m,n,br=0,sum=0, minn[10001], maxx[10001];

int main (){
int i, j;

 cin>>k>>m>>n;

 for(i=1;i<=m-1;i++){
    minn[1]=maxx[1]=i;

    for(j=1;j<=n;j++){
        if(minn[j]-k>0){
            minn[j+1]-=k;
            br++;
        }
        else {
            minn[j+1]+=k;
            br--;
        }
        if(minn[j]+k<m) br++;
        if(maxx[j]-k>0) br++;
        if(maxx[j]+k<m){
            maxx[j+1]+=k;
            br++;
        }
        else {
            maxx[j+1]-=k;
            br--;
        }
        sum+=br;
        br=0;
    }

 }

 cout<<sum;

 return 0;
}
