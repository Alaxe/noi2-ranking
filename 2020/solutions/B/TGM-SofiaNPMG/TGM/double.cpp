#include <iostream>
#include <algorithm>
using namespace std;

const int max_n=256;
long long maxans=-1;
long long n,w1,w2,N[max_n],i,z;
bool u[max_n];
void din(bool used[max_n], long long r1, long long r2, long long currans){
    if(currans>maxans){
        maxans=currans;
    }
    long long j,k;
    for(j=0;j<n;j++){
        if(!used[j]){
            used[j]=true;
            if(r1-N[j]>=0){
                din(used,r1-N[j],r2,currans+N[j]);
            }
            if(r2-N[j]>=0){
                din(used,r1,r2-N[j],currans+N[j]);
            }
            used[j]=false;
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    cin >> n >> w1 >> w2;
    for(i=0;i<n;i++){
        cin >> N[i];
    }
    for(i=0;i<n;i++){
        u[i]=true;
        if(w1-N[i]>=0){
            din(u,w1-N[i],w2,N[i]);
        }
        if(w2-N[i]>=0){
            din(u,w1,w2-N[i],N[i]);
        }
        u[i]=false;
    }
    cout << maxans << endl;
return 0;
}
