//#include <iostream>
//#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 1024
#define MOD 123456789012345
int a[MAXN]={};
bool matrix[MAXN][MAXN]={};
long long ans=0, maxm=-1, i, j, l, d, it, n, it1;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //clock_t t;
    scanf("%lld", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
        if(a[i]>maxm) maxm=a[i];
    }
    //t=clock();
    for(i=0;i<n-1;i++){
        it=0;
        for(j=i+1;j<n;j++){
            it=0;
            if(a[j]-a[i]>0&&matrix[i][j]==false){
                d=a[j]-a[i];
                matrix[i][j]=true;
                it=1;
                if(d*(it+1)<=maxm){
                    for(l=j+1;l<n;l++){
                        if(d*(it+1)>maxm) break;
                        if(a[l]-a[i]==(it+1)*d){
                            matrix[i][l]=true;
                            it++;
                            //cout<<a[i]<<" "<<a[l]<<endl;
                            if(d*(it+1)>maxm) break;
                        }
                    }
                }
            }
            it1=0;
            for(l=1;l<=it;l++) it1=(((int)(it/l))%MOD+it1%MOD)%MOD;
            ans=(ans%MOD+it1%MOD)%MOD;
        }
    }
    printf("%lld\n", ans);
    //cout<<(double)(t-clock())<<endl;
    return 0;
}
