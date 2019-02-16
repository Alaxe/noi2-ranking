#include<iostream>
using namespace std;
int main() {
    int n;
    int chisla[100001];
    int up[100001],upMax;
    int down[100001],downMax;
    int sbor=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>chisla[i];
        up[i]=down[i]=1;
    }
    for(int i=0; i<n; i++) {
        upMax=0;
        for(int j=0; j<i; j++) {
            if(chisla[j]<chisla[i]) {
                if(upMax<up[j]) {
                    upMax=up[j];
                }
            }
        }
        up[i]=upMax+1;
    }
    for(int i=n-1; i>=0; i--) {
        downMax=0;
        for(int j=n-1; j>i; j--) {
            if(chisla[j]<chisla[i]) {
                if(downMax<down[j]) {
                    downMax=down[j];
                }
            }
        }
        down[i]=downMax+1;
    }
    for(int i=0; i<n; i++) {
        //cout<<chisla[i]<<" : "<<up[i]<<" + "<<down[i]<<" ; "<<sbor<<endl;
        if(up[i]+down[i]>sbor) {
            sbor=up[i]+down[i];
        }
    }
    cout<<sbor-1;
    return 0;
}
