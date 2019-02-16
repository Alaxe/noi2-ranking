#include <iostream>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	int broi;
	broi=0;
	int c[a+b+1];
	for(int o=0;o<=a+b;o++){
		c[o]=0;
	}
	for(int i=a;i<=b;i++){
		for(int j=1;j<=i;j++){
			if(j%i==0)c[i-1]++;
		} if(c[i-1]%2==1)broi++;
}
cout<<broi/4;
}
