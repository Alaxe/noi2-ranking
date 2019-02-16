#include<iostream>
using namespace std;
int main(){
long long n,x=0,y=1;
cin>>n;
for( ;((y/2)+1)!=n;y=y+2){
    x=x+y;
}
x=x+n;
cout<<x<<endl;
return 0;
}
