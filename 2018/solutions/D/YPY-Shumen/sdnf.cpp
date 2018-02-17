#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;





int main() {
	long long int n;
	cin>>n;
	long long int p=1;
	for(long long int i=1;i<n;i++){
        p=p*i;
	}
	long long int sum=0;
	while(p>0){
        sum+=p%10;
        p=p/10;

	}
	cout<<sum<<endl;
		return 0;
}
