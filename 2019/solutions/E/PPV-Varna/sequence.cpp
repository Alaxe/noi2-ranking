#include<iostream>
using namespace std;
int main() {
int n,k=1,pn=0;
cin>>n;
while(k<=n)
{
    if(k<n)pn=pn+(2*k-1);
    else pn=pn+n;
    k++;
}
cout<<pn;
}
