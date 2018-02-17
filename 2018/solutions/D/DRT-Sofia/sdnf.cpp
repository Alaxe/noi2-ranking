#include <iostream>

using namespace std;
unsigned long long chislo;
unsigned long long  fakt[10000];
int i;
unsigned long long  vmi=1;
int main()
{
	long long cifri[100000];
	long long sbor=0;
   cin>>chislo;
   for(i=1;i<=chislo;i++){
	fakt[i]=i;
	//cout<<fakt[i]<<" "<<endl;
   }
	for(i=1;i<=chislo;i++){
		if(i<chislo){
			vmi=vmi*fakt[i+1];
		}
	}
	cout<<vmi<<endl;
	for(i=0;i<1000;i++){
		cifri[i]=vmi%10;
		vmi=vmi/10;
	}
	for(i=0;i<1000;i++){
		sbor=sbor+cifri[i+1];
	}
	cout<<sbor+cifri[0]<<endl;
    return 0;
}
