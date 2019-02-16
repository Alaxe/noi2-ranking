#include<iostream>
using namespace std;
int d(int q){
    int s,a,k,l;
    s=a=k=l=0;
    k=q;
    while(k>0){
        a=k%10;
        s=s+a;
        k=k/10;
    }
    l=q+s;
    return l;
}
int main(){
int n,m,br=1;
cin>>n>>m;
while(1){
    if(d(n)<m) br++;
    else if(d(n)>m) break;
    n=d(n);
}

cout<<br;

return 0;
}
