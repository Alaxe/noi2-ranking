#include<iostream>
using namespace std;
int main()
{
	long long n,q,vhod[10001],maximalnaVisochina = 0,obshtBroiKapki = 0;
	cin>>n;
	for(int i = 0; i < n;i++){
		cin>>vhod[i];
		if(vhod[i] > maximalnaVisochina)
		{
			maximalnaVisochina = vhod[i];
		}
	}
	cin>>q;
	for(int i = 0; i < n; i++)
	{

		if(vhod[i] < maximalnaVisochina)
		{
			obshtBroiKapki = obshtBroiKapki + ((maximalnaVisochina - vhod[i])*q);
		}
	}
	cout<<obshtBroiKapki<<endl;
return 0;
}
