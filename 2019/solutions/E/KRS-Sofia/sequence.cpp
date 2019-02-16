#include<iostream>
using namespace std;
int main(){
long long n, br, nomerN=0, brChN;
cin>>n;
brChN=n*2-1;
for(br=1;br<brChN;br=br+2){
    nomerN=nomerN+br;
}
nomerN=nomerN+n;
cout<<nomerN;
return 0;
}
