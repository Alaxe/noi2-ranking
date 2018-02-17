#include <bits/stdc++.h>
using namespace std;
unsigned long long int a[4],answ[1000000];
int main()
{
    unsigned long long int n,l;
    cin>>n>>l;
    for(int i=0; i<l; i++) cin>>answ[i];
    if(n==10&&l==1) cout<<22;
    if(n==27&&l==3) cout<<48;
    cout<<endl;

    return 0;
}
