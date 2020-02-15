#include <iostream>
using namespace std;
int main() {
	int n,u,v;
	cin>>n>>u>>v;
	long long volume=0;
	int nums[n];
	for(int i=0; i<n; i++){
	cin>>nums[i];	
	}
    for(int j=0; j<n-1; j++){
    	if(nums[j]<=nums[j+1])volume+=u*v*nums[j];
    	else {
    		if(nums[j]>nums[j+2])volume+=nums[j+2]*u*v;
    		else volume*=nums[j]*u*v;
    	}
    }
    cout<<volume;
	return 0;
}
