#include<iostream>
using namespace std;
int main(){
	long long N,L,Lyt[3],i,br,d=0,brc=0,d2,i2,i3;
	bool inaLiLipsvashtaCifra=true,r=true;
	cin>>N>>L;
	for(i=0;i<L;i++){
		cin>>Lyt[i];
	}
	for(br=0;br<N;br++){
		d++;
	    d2=d;
		while(inaLiLipsvashtaCifra==true){
			while(d>0){
				d=d/10;
		        brc++;
				}
			for( ;i>0;i--){
				for(i2=0,i3=10;i2<brc;i2++,i3=i3*10){
					if(Lyt[i-1]==(d2%i3)/(i3/10)){
						r==false;
					}
				}
			}
			if(r=true){
				inaLiLipsvashtaCifra=false;
			}
			d=d2;
			d++;
		}
		inaLiLipsvashtaCifra=true;
		r=true;

	}
	cout<<d;
return 0;
}
