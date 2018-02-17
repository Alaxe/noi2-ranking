#include<iostream>
using namespace std;
int main(){
long long n,k,turseno=1,broqch=1,pomnqturseno;
cin>>n;
cin>>k;
while(broqch<n){
	turseno=turseno*10;
	pomnqturseno=turseno;
	broqch++;
}

for(turseno;turseno%k!=0;turseno++){}
if(turseno/10>=pomnqturseno){
	cout<<"NO";

}else{
	cout<<turseno;
}
return 0;
}
