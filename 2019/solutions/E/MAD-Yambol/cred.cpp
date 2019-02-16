#include<iostream>
using namespace std;
int main(){
int n,m,count1;
cin>>n>>m;
for(count1=0;n<m;count1++){
if(n<10)n=n+n;
else
if(10<n<100)n=n+(n/10+(n-(n/10)*10));
else
if(100<n<1000)n=n+n/100+(n/10-(n/100)*10)+n-(n/10)*10;
else
n=n+1;
}
cout<<count1<<endl;
}
