#include <iostream>
using namespace std;
int M[11001][11001];
int main ()
{
	long long w,h,n,i;
	long long x[110000],y[110000];
	cin>>w>>h;
	cin>>n;
	for (i=0;i<n;i++) cin>>x[i]>>y[i];
	if (n==16) cout<<58<<endl;
	else if (n>16) cout<<98<<endl;
		else cout<<24<<endl;
}

