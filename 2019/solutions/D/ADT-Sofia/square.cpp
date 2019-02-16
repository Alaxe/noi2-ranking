#include <iostream>
using namespace std;

long long nod( long long a, long long b){
    while( a!=0 && b!=0 ){
        if( a>b )a=a%b;
        else b=b%a;
    }
    if( a!=0 ){
        return a;
    }
    return b;
}
long long vhod[100000];

int main () {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ios_base::sync_with_stdio(false);
cout.tie(NULL);

bool dali=true;
long long n, nokNaVsichki=1;
cin>>n;
for( long long i=0; i<n ; i++){
    cin>>vhod[i];
    nokNaVsichki=nokNaVsichki*vhod[i]/nod( nokNaVsichki, vhod[i]);
}
long long c=1;
for( long long i=0; dali ; c++){
    if( (c*c)>nokNaVsichki ){
        if( (c*c)%nokNaVsichki==0 ){
            dali=false;
        }
    }
}
cout<<c-1<<endl;
    return 0;
}
