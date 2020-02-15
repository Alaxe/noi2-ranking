#include<iostream>

using namespace std;


int main(){
	int n, count=0;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	while(a[0]>a[1]) {
		a[0]--;
		count++;
	} 
	for(int i=1; i<n-1; i++) {
		if (a[i]>a[i+1]) {


				while (a[i] < a[i-1]) {
					a[i]++;
					count++;
				}
			
			
			if (a[i] > a[i-1]) {
				while (a[i] > a[i+1]) {
					a[i]--;
					count++;
				}
			}

		} 
	}
	



	
	while(a[n-1] < a[n-2]) {
		a[n-1]++;
		count++;
	}
	 
	
	cout << count;
	
	return 0;
}

