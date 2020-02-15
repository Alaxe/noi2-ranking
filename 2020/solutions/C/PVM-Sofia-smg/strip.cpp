//ready
#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
cin>>n>>k;
    double otg=1;
k=min(k-1,n-k);
    for (int q=1;q<=k;q++) {
        otg*=n-q;
        otg/=q;
    }
long long otg1=otg;
cout<<otg1<<"\n";
return 0;
}

