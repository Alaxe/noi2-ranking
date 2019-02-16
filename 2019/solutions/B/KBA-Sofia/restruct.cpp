#include<iostream>
using namespace std;
int main() {
    int n,m,l,zaplata,br,x;
    long long sbor=0;
    cin>>n>>zaplata;
    for(int a=0; a<n; a++) {
        cin>>br;
        for(int b=0; b<br; b++) {
            cin>>x;
        }
    }
    m=1;
    l=1;
    while(n-m>=0) {
        n-=m;
        sbor+=m*l;
        m*=2;
        l++;
    }
    sbor+=n*l;
    sbor*=zaplata;
    cout<<sbor;
    return 0;
}
