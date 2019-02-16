#include<iostream>
using namespace std;
int main(){
long long n,m,br=0;
cin>>n>>m;
    for(;n<m;){
        for(;;){
if(n<10){
    n*=2;
    br++;
    break;
}
if(9<n && n<100){
    n=n+n/10+n%10;
    br++;
    break;
}
if(99<n && n<1000){
    n=n+n/100+n%100/10+n%10;
    br++;
    break;
}
if(999<n && n<10000){
    n=n+n/1000+n%1000/100+n%100/10+n%10;
    br++;
    break;
}
if(9999<n && n<100000){
    n=n+n/10000+n%10000/1000+n%1000/100+n%100/10+n%10;
    br++;
    break;
}
        }
    }
cout<<br;
return 0;
}
