#include<iostream>
#include<cmath>
using namespace std;
bool a[43];
int main(){
    int n,k,val;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>val;
        a[val]=true;
    }
    bool keep=true, trig=true;
    for(int i=1;trig;i++){
        keep=true;
        for(int x=0;keep && x<43;x++){
            if(a[x]){
                double tmp = pow(i,k);
                if((int)tmp%x != 0)keep=false;
            }
        }
        if(keep){
            trig=false;
            cout<<i<<endl;
        }
    }
    return 0;
}
