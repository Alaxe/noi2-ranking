#include <iostream>
using namespace std;
int main() {
int n,u,v;
cin>>n>>u>>v;
int wall[n];
for (int i=0;i<n;i++) {
    cin>>wall[i];
    if (i>0) {
        wall[i]=wall[i]+wall[i-1];
    }
}
cout<<wall[n]*u*v;
}
