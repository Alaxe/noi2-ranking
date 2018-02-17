#include<iostream>
using namespace std;
int main(){
long long n,q,ng,p=0;
cin>>n;
long long a[n],br;
for(br=0;br<n;br++){
    cin>>a[br];
}
cin>>q;
ng=a[0];
for(br=0;br<n;br++){
    if(a[br]>ng){
       ng=a[br];
    }
}
for(br=0;br<n;br++){
    p=p+(ng-a[br]);
}
cout<<p*q;




return 0;
}
