//#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdio>
using namespace std;
#define MAXN 100100
#define MAXH 110000000
int hw[MAXH]={};
int n, w, h, i, x[MAXN]={}, y[MAXN]={}, j;
map<int, int> m;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    memset(hw,-1,sizeof(hw));
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d", &x[i], &y[i]);

    long long area=0;
    for(i=1;i<n;i++){
            bool flag=false;
        if(x[i-1]==x[i]&&x[i+1]!=x[i]) {y[i]--; flag=true;}
        if(y[i]==y[i-1]&&x[i]<x[i-1]&&y[i]>y[i+1]) {y[i]--; flag=true;}
        if(hw[y[i]]==-1) {
                hw[y[i]]=w-x[i];
                area+=hw[y[i]];
                if(x[i-1]==x[i]&&y[i-1]<y[i]){
                    //cout<<i<<" "<<x[i-1]<<" "<<x[i]<<endl;
                for(j=y[i-1];j<=y[i];j++){
                    if(hw[j]==-1) {hw[j]=w-x[i]; area+=hw[j];}
                    else if(w-x[i]<hw[j]) {area-=hw[j]; hw[j]=w-x[i]; area+=hw[j];}
                }
            }
        }
        else
            if(x[i-1]==x[i]&&y[i-1]<y[i]){

                for(j=y[i-1];j<=y[i];j++){
                    if(hw[j]==-1) hw[j]=w-x[i];
                    else if(w-x[i]<hw[j]) {area-=hw[j]; hw[j]=w-x[i]; area+=hw[j];}
                }
            }
            else if(w-x[i]<hw[y[i]]) {area-=hw[y[i]]; hw[y[i]]=w-x[i]; area+=hw[y[i]];}
        if(flag==true) y[i]++;
    }
    printf("%lld\n", area);
    return 0;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10

*/
