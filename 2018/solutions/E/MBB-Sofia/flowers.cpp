#include<iostream>
#include<algorithm>
using namespace std;
int main(){
long long n,q,t=0,o,d;
cin>>n;
long long c[n];
for(d=0;d<n;d++){
    cin>>c[d];
}
cin>>q;
for(o=0;o!=n;c[o]++){
    if(c[o]==*max_element(c,c+n)){
        o++;
    }else{
    t=t+q;
    }
}
cout<<t;
return 0;
}
