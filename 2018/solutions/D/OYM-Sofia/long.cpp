#include<iostream>
using namespace std;
int main(){
long long a,b,c=1;
cin>>a>>b;
for(int i=0;i<a-1;i++){
    c*=10;
}
if(c%b>0){
    cout<<c+b-c%b;
}else{
    cout<<c;
}
return 0;
}


