#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
char vhod='.';
long long prov=2,st=1;

long long cif(int x){
	long long i=0;
	while(x>0){
		x/=10;
		i++;
	}
	return i;
}

int main(){
	for(int i=1;vhod!='\n';i++){
		scanf("%c", &vhod);
		if(i==cif(prov)){
			i=0;
			prov*=2;
			st++;
		}
	}
	cout<<st-1<<endl;
return 0;
}
