#include<iostream>
using namespace std;
int a[100000],dp1[100000],dp2[100000],dp3[100000];
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n,maxx1=-1,maxx2=-1,maxx3=-1;
     cin>>n;
     for(int i=0; i<n; i++) cin>>a[i];
     
     for(int i=0; i<n; i++)
     {
     	dp1[i]=1;
     	dp2[i]=1;
     	for(int j=0; j<i; j++)
     	{
     		if(a[j]<a[i]&&dp1[j]+1>maxx1) maxx1=dp1[j]+1;
     		  else if(a[j]>a[i]&&dp2[j]+1>maxx2) maxx2=dp2[j]+1;
		}
		if(dp1[i]<maxx1) dp1[i]=maxx1;
		if(dp2[i]<maxx2) dp2[i]=maxx2;
		maxx1=-1;
		maxx2=-1;
	 }
	 for(int i=n-1; i>=0; i--)
	 {
	 	dp3[i]=1;
	 	for(int j=n-1; j>i; j--)
	 	{
	 		if(a[j]<a[i]&&dp3[j]+1>maxx3) maxx3=dp3[j]+1;
		 }
		if(dp3[i]<maxx3) dp3[i]=maxx3;
		 maxx3=-1;
	 }
/*
	 for(int i=0; i<n; i++) cout<<dp1[i]<<" ";
	 cout<<endl;
	 for(int i=0; i<n; i++) cout<<dp2[i]<<" ";
	 	 cout<<endl;
	 for(int i=0; i<n; i++) cout<<dp3[i]<<" ";
	 	 cout<<endl;
*/
	 for(int i=0; i<n; i++)
	 {
	 	dp3[i]=dp1[i]+dp3[i]-1;
	 	if(dp3[i]<3) dp3[i]=0;
	 	if(dp1[i]>maxx1) maxx1=dp1[i];
	 	if(dp2[i]>maxx2) maxx2=dp2[i];
	 	if(dp3[i]>maxx3) maxx3=dp3[i];
	 }
	 maxx1=max(maxx1,maxx2);
	 maxx3=max(maxx3,maxx1);
	 cout<<maxx3<<endl;
}

