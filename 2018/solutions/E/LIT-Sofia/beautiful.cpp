#include<iostream>
using namespace std;
int main(){
long long  n,k,b=1;
cin>>n>>k;
while(n>1){
    b=b*10;
    n=n-1;
}
for(int i=b;i<=b*10-1;i++){
    if(i%k==0){
        cout<<i;
       break;
    }

}

if(k>b*10-1){
    cout<<"NO";
}
cout<<endl;

return 0;
}
