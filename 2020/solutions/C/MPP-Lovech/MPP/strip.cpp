#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int N, K,  z;
	
	cin>>N;

	cin>>K;
	if (K==1 || K==N ){
	z=1;
	cout<<z<<endl;
	}
	else {
	if(K==2)
	{
		z=2+N-K-1;
		cout<<z<<endl;
	}
	else{
		z=3*N-2*K-5;
		cout<<z<<endl;
	}
	}
	
	
	
	return 0;
}
