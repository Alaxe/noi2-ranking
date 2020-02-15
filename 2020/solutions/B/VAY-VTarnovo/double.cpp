#include <iostream>
using namespace std;
int main()
{
	int a[200],n,w1,w2,w12[200],j=0;
	cin>>n>>w1>>w2;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
	w12[i]=a[i];
	 while(w12[i]<=w1||w12[i]<=w2)
	 {
		if((w12[i]+a[j+1])<=w1||(w12[i]+a[j+1])<=w2)w12[i]=w12[i]+a[j+1];
		j++;
	 }
    } 
    cout<<w12;
}
