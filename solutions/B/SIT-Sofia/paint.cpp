#include<iostream>
using namespace std;
int tsqlo[11001][11001];
long long litsa[11001],otg[11001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
int shir,dulj,n=0,t=0,k=0;
int x,y,w,h,a=0,b=0;
cin>>dulj>>shir;
litsa[0]=dulj*shir;
cin>>n;
a=1;
b=1;
for(int i=0;i<n;i++){
    cin>>x>>y>>w>>h;

    if(i==0){
        for(int j=x;j<x+w;j++){
            for(int p=y;p<y+h;p++){
               tsqlo[j][p]=1;
            }
        }
        litsa[1]=w*h;
        litsa[0]-=litsa[1];
            }else{
                 k=tsqlo[x][y];
    for(int j=x;j<x+w;j++){
            for(int p=y;p<y+h;p++){

                   tsqlo[j][p]=i+1;
            }
        }
        litsa[i+1]=w*h;
        litsa[k]-=litsa[i+1];
    }
   // cout<<litsa[0]<<" "<<litsa[1]<<" "<<litsa[2]<<" "<<litsa[3]<<"\n";
}


cin>>t;
for(int i=0;i<t;i++){
    cin>>x>>y;
    k=tsqlo[x][y];
    otg[i]=litsa[k];
}
for(int i=0;i<t;i++){
    cout<<otg[i]<<"\n";
}
return 0;
}
/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
/*
4 7
3
1 2 3 5
2 3 1 1
2 5 1 1
5
0 0
2 2
2 3
3 4
2 5
*/
