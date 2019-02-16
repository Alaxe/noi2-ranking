#include<bits/stdc++.h>
using namespace std;
int main () {
long long m,n,k,brch=0,brsr=0;
cin>>n>>k;
brch=n*n-n-n+1;
for (m=n;brsr<k;m++) {
    brch=m+(m-1)+brch;
    if (n==m) brsr++;
    else brsr=brsr+2;
    //cout<<m<<" "<<brsr<<endl;
}
if (brsr==k) brch=brch-(n-1);
else {
        brch=brch-(m-1);
        brch=brch-((m-2)-n);
}

cout<<brch;
}
