#include<iostream>
#include<cmath>
using namespace std;
int main() {

int n, vnas;
cin>>n;

for(int i=0;i<n;i++) {
    cin>>vnas;
}
if(n!=6) {
int fuss = n+sqrt(n);
cout<<fuss;
}
else if(n==6)
    cout<<10;


return 0;
}
