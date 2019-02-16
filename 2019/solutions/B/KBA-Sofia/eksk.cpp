#include<iostream>
using namespace std;
int main() {
    long long izhod;
    int n;
    int x[200001],y[200001];
    cin>>n;
    for(int a=0; a<n; a++) {
        cin>>x[a]>>y[a];
    }
    izhod=n/3;
    if(n%3==2) {
        izhod++;
    }
    cout<<izhod;
    return 0;
}
