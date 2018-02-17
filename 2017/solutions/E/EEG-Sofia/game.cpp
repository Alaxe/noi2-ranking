#include<iostream>
using namespace std;
int main(){
long long k,m,chislok,chislo[100000];
cin>>k>>m;
chislok=0;
for(int i;chislok<k;i++){
cin>>chislo[i];
if(chislo[i]%2=0){
chislok=chislok+chislo[i];
}
}
cout<<chislok;















return 0;
}
