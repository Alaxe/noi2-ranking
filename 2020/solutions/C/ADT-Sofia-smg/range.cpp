#include <bits/stdc++.h>
using namespace std;

long long chisla[1000000], poMalkiOt[1000000], max1=-1;

int main () {

long long br, vhod;
cin>>br;
for(long long i=0 ; i<br ; i++){
    cin>>vhod;
    chisla[vhod]++;
    if(max1<vhod)max1=vhod;
}
poMalkiOt[1]=chisla[1];
for(long long i=2 ; i<=max1 ; i++){
    poMalkiOt[i]=poMalkiOt[i-1]+chisla[i];
}

long long brZaqvki, a, b;
cin>>brZaqvki;
for(long long i=0 ; i<brZaqvki ; i++){
    cin>>a>>b;
    if(a>max1){
        cout<<0<<endl;
    }else{
        if(a==b){
            cout<<chisla[a]<<endl;
        }else{
            if(a<max1 and b>max1 ){
                cout<<poMalkiOt[max1]-poMalkiOt[a]+1<<endl;
            }
            if( a<max1 and b<max1 ){
                cout<<poMalkiOt[b]-poMalkiOt[a]+1<<endl;
            }
        }
    }
}


    return 0;
}
