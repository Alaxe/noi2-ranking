#include <iostream>
using namespace std;
int main (){
long long mmZApolivane=0,broqchka,n,q,naiG=0;
cin>>n;
long long a[n];
for(broqchka=0;broqchka<n;broqchka++){
    cin>>a[broqchka];
    if(a[broqchka]>naiG){
        naiG=a[broqchka];
    }
}
cin>>q;
for(broqchka=0;broqchka<n;broqchka++){
    if(a[broqchka]<naiG){
        mmZApolivane=mmZApolivane+(naiG-a[broqchka]);
    }
}
cout<<mmZApolivane*q;
return 0;
}
