#include<iostream>
using namespace std;
int k,m,n;
///k: + или - k
///m: всеки ел. е по-малък от m
///n: дължина на редицата
long long memoization[51][51];
///       memoization[n ][m ]
long long result(int lastDig,int sizeR){
    if(memoization[sizeR][lastDig]!=-1) return memoization[sizeR][lastDig];
    if(sizeR==1) return 1;
    bool f=1,s=1;
    if(lastDig-k<=0) f=0;
    if(lastDig+k>=m) s=0;
    if(f==0 and s==0){
        memoization[sizeR][lastDig]=0;
        return 0;
    }
    if(f==0 and s==1){
        memoization[sizeR][lastDig]=result(lastDig+k,sizeR-1);
        return result(lastDig+k,sizeR-1);
    }
    if(f==1 and s==0){
        memoization[sizeR][lastDig]=result(lastDig-k,sizeR-1);
        return result(lastDig-k,sizeR-1);
    }
    if(f==1 and s==1){
        memoization[sizeR][lastDig]=result(lastDig+k,sizeR-1)+result(lastDig-k,sizeR-1);
        return result(lastDig+k,sizeR-1)+result(lastDig-k,sizeR-1);
    }
}
int main(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            memoization[i][j]=-1;
        }
    }
    cin>>k>>m>>n;
    long long ans=0;
    for(int last=1;last<m;last++){
        ans+=result(last,n);
    }
    cout<<ans<<endl;
return 0;
}
