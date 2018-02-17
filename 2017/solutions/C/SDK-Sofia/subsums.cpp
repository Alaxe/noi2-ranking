#include<iostream>
using namespace std;
int main(){
    int n, brsb=0;
    cin>>n;
    int m[n], i;
    bool srsb[100000];
    for(int i=0;i<100000;i++){
        srsb[i]=false;
    }
    for(i=0;i<n;i++){
        cin>>m[i];
        if(srsb[m[i]]==false){
            brsb++;
            srsb[m[i]]=true;
        }
    }
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(srsb[m[i]+m[j]]==false){
                brsb++;
                srsb[m[i]+m[j]]=true;
             }
        }
    }
    cout<<brsb;
    return 0;
}
