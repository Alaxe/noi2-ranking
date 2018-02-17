#include<iostream>
using namespace std;
long long n,q,p[10000],r;
int main () {
cin>>n;
for(r=0;r<n;r++){
cin>>p[r];
}cin>>q;
for(r=0;r<n;r++){

cout<<p[r]*q;
}
return 0;
}
