#include<iostream>
using namespace std;
long long cvetq[10001];
int main() {
    long long n,q,naj_golqmo=0,i=0,obshto=0;
    cin>>n;
    for(;i<n;i++){
        cin>>cvetq[i];
        if(cvetq[i]>=naj_golqmo){
            naj_golqmo=cvetq[i];
        }
    }
    cin>>q;
    for(i=0;i<n;i++){
        obshto=obshto+(naj_golqmo-cvetq[i])*q;
    }
    cout<<obshto;
return 0;
}
