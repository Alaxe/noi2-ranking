#include<iostream>
using namespace std;
int main() {
long long broi,zagpech,broqch,cifra,broqch2,pomnq=1;
bool stavali=false;
bool namerihli=false;
cin>>broi>>zagpech;
long long zagcifri[zagpech];
for(broqch=0;broqch<zagpech;broqch++){
	cin>>zagcifri[broqch];

}
broqch=1;
while(broi>0){
	while(stavali==false){
		while(namerihli==false  &&  stavali==false){
			cifra=broqch%10;
			broqch=(broqch-cifra)/10;
			broqch2=0;
			if(broqch==0){
				stavali=true;
			}
			while(broqch2<zagpech){
				if(cifra==zagcifri[broqch2]){

					namerihli=true;

				}
				broqch2++;
			}

		}
		pomnq++;
		broqch=pomnq;
		namerihli=false;
	}
	namerihli=false;
	stavali=false;
	broi=broi-1;
	pomnq++;
}
cout<<pomnq+1;

return 0;
}
