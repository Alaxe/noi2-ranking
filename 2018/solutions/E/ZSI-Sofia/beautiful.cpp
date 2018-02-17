#include<iostream>
#include<cmath>
using namespace std;
int main () {
long long chislo,n,k,a,b;
cin>>n>>k;
a=pow (10,n);
b=pow (10,(n-1));
for (int i=a;i>=b;i--) {
    if (i%k==0) {
        chislo = i;
    }
}
cout<<chislo;
return 0;
}
