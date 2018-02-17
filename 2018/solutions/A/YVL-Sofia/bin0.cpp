#include<iostream>
using namespace std;
unsigned long long pasc[61][61], pow2[64];
unsigned long long assignlarger(unsigned long long n){
    for(int i=0;i<64;i++){
        if(pow2[i]==n) return i;
    }
    return -1;
}
unsigned long long pow(unsigned long long r){

}
int kolkoedinici(unsigned long long u){
    int res=0;
    for(int i=60;i>=0;i--){
        if(pow2[i]<u){
            u-=pow2[i];
            res++;
        }
    }
    return res;
}
int main(){
    pasc[0][0]=1;
    pasc[1][0]=1;
    pasc[1][1]=1;
    pow2[0]=1;
    pow2[1]=2;
    for(int i=2;i<61;i++){
        pasc[i][0]=1;
        for(int j=1;j<=i;j++){
            pasc[i][j]=pasc[i-1][j-1]+pasc[i-1][j];
        }
        pow2[i]=pow2[i-1]*2;
    }
    unsigned long long s, t, z;
    cin>>s>>t>>z;
    unsigned long long logs=assignlarger(s);
    unsigned long long logt=assignlarger(t), ans;
    if(s==pow2[logs]&&t==pow2[logt]){
      //  logs++;
    //    logt;
        ans=0;
        for(int i=logs;i<logt;i++){
            ans+=pasc[i][z];
        }
        if(logt==z) ans++;
        cout<<ans<<"\n";
    }else{
        int ans=0;
        for(int i=s;i<=t;i++){
            if(kolkoedinici(i)==z) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
