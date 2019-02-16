#include <iostream>
using namespace std;

long long br[13];

int main(){
ios_base::sync_with_stdio(false);
cin.tie();
    bool buf;
    long long n,k,N[10001],prosti[13]={2,3,5,7,11,13,17,19,23,29,31,37,41},i,j,res=1;
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> N[i];
    }
    for(i=0;i<13;i++){
        long long pr=prosti[i];
        for(j=0;j<n;j++){
            if(N[j]%pr==0){
                buf=true;
                N[j]/=pr;
            }
        }
        if(buf){
            br[i]++;
            buf=false;
            i--;
        }
    }
    int broi;
    for(i=0;i<13;i++){
        if(br[i]%k==0){
            broi=br[i]/k;
        }else{
            broi=(br[i]/k)+1;
        }
        for(j=0;j<broi;j++){
            res*=prosti[i];
        }
    }
    cout << res << endl;
return 0;
}
