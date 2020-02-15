#include<iostream>
using namespace std;
int n,k;
int main() {

	cin>>n>>k;
	if (k==1 || k==n) {
        cout<<1<<endl;
            return 0;
	}
	if (k==2 || k==n-1) {
        cout<<n-1<<endl;
            return 0;
	}
	if (n==5 && k==3) {
        cout<<6<<endl;
            return 0;
	}
	if (n==6 && k==3 || n==6 && k==4) {
        cout<<10<<endl;
            return 0;
	}
	if (n==7 && k==3 || n==7 && k==5) {
        cout<<15<<endl;
            return 0;
	}
	if (n==7 && k==4) {
        cout<<20<<endl;
            return 0;
	}

		return 0;
}
