#include<iostream>
using namespace std;

int main ()
{
	unsigned long long m, n;
	
	unsigned long long z;
	unsigned long long count = 0;
	
	cin>>m>>n;
	
	for (int y = 0; y < n/2 + 1; y++) {
		z = y + 1;
		if (y * z <= n && y * z >= m) {
			cout<<y*z<<endl;
			count++;
		}
	}
	
	cout<<endl<<count;
	return 0;
}

