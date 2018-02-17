#include<iostream>
#include<algorithm>
using namespace std;

struct zaPregled
{
	long long a;
	long long p;
};

bool cmp(zaPregled a1, zaPregled a2)
{
	if(a1.a<a2.a){
		return 1;
	}
	return 0;
}

zaPregled pacient[1024];
long long t;
int main(){
	int i;
	for(i=0;cin;i++){
		cin>>pacient[i].a>>pacient[i].p;
	}
	sort(pacient, pacient+i, cmp);
	for(int r=0;r<i;r++){
		if(pacient[r].a>t){
			t=pacient[r].a;
		}
		t+=pacient[r].p;
		//cout<<t<<endl;
	}
	cout<<t-pacient[i-1].a<<endl;
return 0;
}
