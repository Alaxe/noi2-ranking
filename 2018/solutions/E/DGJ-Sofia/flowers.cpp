#include<iostream>
using namespace std;
int main() {
long long broicvetq,obstbroi=0,ng=0,kapkivoda,broqch;
cin>>broicvetq;
long long visochina[broicvetq];
for(broqch=0;broqch<broicvetq;broqch++){
	cin>>visochina[broqch];
	obstbroi=obstbroi+visochina[broqch];
	if(ng<visochina[broqch]){
		ng=visochina[broqch];

	}
}
cin>>kapkivoda;

cout<<(ng*broicvetq-obstbroi)*kapkivoda;


return 0;
}
