#include <iostream>
using namespace std;

long long ans=0,n,br,u,N[1000005],i,sb[64][64],j,z;
bool used[64];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    cin >> n >> u;
    for(i=0;i<n;i++){
        cin >> N[i];
        used[N[i]]=true;
    }
    for(i=1;i<=u;i++){
        sb[i][0]=i;
        sb[1][i]=1;
        if(used[i]){
            br++;
        }
    }
    for(i=1;i<br;i++){
        for(j=1;j<=u;j++){
            sb[j][i]=sb[j-1][i]+sb[j][i-1];
        }
    }
    ans=sb[u-br+1][br-1];
    /*for(i=1;i<br-1;i++){
        for(j=2;j<=u;j++){
            sb[j]+=sb[j-1];
        }
    }*/
    cout << ans/2 << endl;
return 0;
}

