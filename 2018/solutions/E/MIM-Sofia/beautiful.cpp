#include <iostream>
using namespace std;
int main (){
long long broqchka,nachalno,kraino,n,k;
cin>>n>>k;
nachalno=1;
kraino=1;
for(broqchka=0;broqchka<n-1;broqchka++){
    nachalno=nachalno*10;
    kraino=kraino+nachalno;
}
kraino=kraino*9;
while(nachalno%k!=0){
    nachalno=nachalno+1;
}
if(nachalno<=kraino){
    cout<<nachalno;
}else{
cout<<"NO";
}
return 0;
}
