#include <iostream>
using namespace std;
int main() {
	long long n, helper=0;
	cin>>n;
	long long b[n];
	for(long long i=0; i<n; i++){
		cin>>b[i];
	}
	long long row[n];
	for(int j=0; j<n; j++){
		row[j]=n-b[j]-helper;
		helper++;
		cout<<row[j]<<" ";
	}
	return 0;
}
