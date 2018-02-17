#include <iostream>
using namespace std;
int main(){
ios::sync_with_stdio(false);
int n, k;
long long t=1, otg=0;
bool minaLi=false;
cin>>n>>k;
for(int i=1; i<n; i++){
    t=t*10;
}
for(int i=0; (t+i)%k!=0; i++){
    otg=t+i;
    minaLi=true;
}
if(minaLi==false){
    cout<<t<<endl;
}else{
    cout<<otg+1<<endl;
}
return 0;
}
