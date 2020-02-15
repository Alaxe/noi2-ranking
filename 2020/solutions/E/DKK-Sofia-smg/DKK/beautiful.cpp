#include <iostream>
using namespace std;
int main(){
long long n,k=1,p=10,broi=0;
cin>>n;
long long a[n];
for(int i=1;i<=n;i++){
if(i/p>0){
    k=k*10;
    p=p*10;
}
if(i/k==i%k || i/k==i%p){
    broi++;

}


}
cout<<broi;


}
