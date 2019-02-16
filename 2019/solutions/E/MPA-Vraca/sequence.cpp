#include <iostream>
using namespace std;
int main() {
	int  n;
	int broi;
	cin>>n;
	if(n==1)cout<<1;
	else{
	
	broi=n;
    for(int i=1;i<n;i++){
    	broi+=i;
    }
    broi+=n-2;
    if(n>=4){
    broi+=n-3;
}
	cout<<broi;
}	}
