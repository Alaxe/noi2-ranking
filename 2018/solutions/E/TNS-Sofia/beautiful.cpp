#include <iostream>
using namespace std;
int main () {
bool ima_li_del=false;
long long k, n, nai_malko=1;
cin>>n>>k;
for(int i=2; i<=n; i++){
    nai_malko=nai_malko*10;
}
for(int j=1; j<=10000000; j++){
    if(nai_malko%k==0){
        break;
        ima_li_del=true;
    }else{
        nai_malko++;
    }
    if((j==10000000) and (ima_li_del==false)){
        cout<<"NO";
    }

}
cout<<nai_malko;

return 0;
}
