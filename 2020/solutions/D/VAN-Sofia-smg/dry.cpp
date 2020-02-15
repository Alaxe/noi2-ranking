#include <iostream>
using namespace std;
int p[103];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,u,v,maxp=0;
    long long otg=0;
    cin>> n >> u >> v;
    for(int i=0;i<n;i++){
        cin>> p[i];
    }
    int br=0,ind=0;
    for(int i=0;i<n;i++){
        i=ind;
        maxp=p[i+1];
        br=0;
        for(int j=i+1;j<n;j++){
            if(p[j]>=maxp){
                maxp=p[j];
                ind=j;
            }
            //cout<< "ind=" << ind << " ";
            if(p[j]>=p[i]) break;
        }
        br=ind-i;
       // cout<< "maxp=" << maxp << " " << "br=" << br << " ";
        if(maxp>p[i]){
            otg+=(p[i]*u*v*br);
            //cout<< p[i]*u*v*br << endl;
        }else{
            otg+=(maxp*u*v*br);
            //cout<< maxp*u*v*br << endl;
        }
    }
    cout<< otg;



    return 0;
}
