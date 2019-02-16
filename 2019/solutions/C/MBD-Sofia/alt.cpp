#include<iostream>
using namespace std;
int mi(int k,int i,int m,int n,int pr,int br){
    pr++;
    if(pr==n){
        br++;
        return br;
    }
    if(i+k>m) mi(k,i-k,m,n,pr,br);
    if(i-k<0) mi(k,i+k,m,n,pr,br);
}
int main(){
    int k,m,n,pr=0;
    long long br=0;
    cin >> k >> m >> n;
    for(int i=1;i<m;i++){
        br=br+mi(k,i,m,n,pr,br);
    }
    cout << k*(m-n)/4+m*(k+n)/4 << endl;
    return 0;
}
