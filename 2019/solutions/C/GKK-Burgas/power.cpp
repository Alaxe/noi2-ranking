#include<iostream>
#include<cmath>
using namespace std;

	int n,k,a;
	int c=1;
	
bool isPrime(int m){
	bool Prime = true; 
	for(int i = 2; i<=sqrt(m);i++){
		if(m==2 || m==3) break;
		if(m%i == 0){
			Prime = false;
			break;
		} 
		
	}
	return Prime; 
}

void PrimeDelitel(int y){

	int i; int br1 = 0; int br2 = 0; int cc=c; int cy=y;
	for(i = 2; i<cy;i++){
		if(y%i != 0) continue;
		while(y%i==0){
			y=y/i;br1++;
		}
		while(cc%i==0){
			cc=cc/i;br2++;
		}
			if(br2 != 0)
			{
				if(br2*k<br1){
					c=c*pow(i, (br1/(br2*k))-1);
					if(br1%(br2*k)!=0){
						c=c*i;
					}
				}
			}
			else{
				if(br2+k<br1){
					c=c*pow(i, (br1/(br2+k))-1);
					if(br1%(br2+k)!=0){
						c=c*i;
					}
				}
				else{
					c*=i;
				}
			}
			br1 = 0; br2 = 0;cc=c;
	}
	
}

int main()
{

	cin>>n>>k;

	for(int i=0;i<n;i++){
		cin>>a;

		if(isPrime(a) == true){
			c*=a;
		}
		else{

		PrimeDelitel(a);

		}
	}
	cout<<c<<endl;
	return 0;
}	

