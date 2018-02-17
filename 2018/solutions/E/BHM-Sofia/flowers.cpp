#include<iostream>
using namespace std;
int main(){
long long n,q,ng=0,obshtoKapki=0,i;
cin>>n;
long long visochina[n];
for(i=0;i<n;i++){
    cin>>visochina[i];
    if(visochina[i]>ng){
        ng=visochina[i];
    }
}
cin>>q;
for(i=0;i<n;i++){
    obshtoKapki+=(ng-visochina[i])*q;
}
cout<<obshtoKapki<<"\n";



return 0;
}
