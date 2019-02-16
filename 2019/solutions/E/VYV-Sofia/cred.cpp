#include<iostream>
using namespace std;
int main(){
int n,m,broi=0;
cin>>n>>m;
while(n<m){
    n=n+n%10+(n%100/10);
    broi=broi+1;
}
cout<<broi;
return 0;
}
