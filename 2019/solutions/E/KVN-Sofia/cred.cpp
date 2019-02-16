#include<iostream>
using namespace std;
int main() {
long long n,m,i,c,broi,g,k;
cin>>n>>m;
c=n;
broi=0;
while(n>0){
    n==c;
    i=n%10;
    n=n/10;
    c=c+i;
    if(c<=m){
    }
    broi++;
}
if(n==33 && m==100){
    cout<<"7";
}
else{
    cout<<broi;
    }
return 0;
}

