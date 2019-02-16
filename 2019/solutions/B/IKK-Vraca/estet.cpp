#include<iostream>
using namespace std;
int i,j;
long long N;

int inc(int a[])
{
	int count1[N];
	int q;
	for(j=0;j<N;j++)
{	q=j;count1[j]=1;
	for(i=q+1;i<N;i++)if(a[i]>a[q]){count1[j]++;q=i;}
}
int max1=count1[0];
for(i=1;i<N;i++)if(count1[i]>max1)max1=count1[i];
	return max1;
}

int down(int a[])
{
	int count2[N];
	int q;
	for(j=0;j<N;j++){
		q=j;count2[j]=1;
	for(i=q+1;i<N;i++)if(a[i]<a[q]){count2[j]++;q=i;}
	 }
int max2=count2[0];
for(i=1;i<N;i++)if(count2[i]>max2)max2=count2[i];
	return max2;
}

int updown(int a[])
{
	int count3[N],k;
	int q;
	for(j=0;j<N;j++)
	{
		q=j;count3[j]=1;
	for(i=q+1;i<N;i++)if(a[i]>a[q]){count3[j]++;q=i;}
					else { k=i; break; }
	for(i=k;i<N;i++)if(a[i]<a[q]){count3[j]++;q=i;}
}
int max3=count3[0];
for(i=1;i<N;i++)if(count3[i]>max3)max3=count3[i];
	return max3;
}

int main()
{
	do{cin>>N;}while(N<=0 || N>100000);
	int a[N];
	
	for(i=0;i<N;i++)do{cin>>a[i];}while(a[i]<=0 || a[i]>100000);
	int x = inc(a),y = down(a),z = updown(a);
	int max=x;
	if(y>max)max=y;
	if(z>max)max=z;
	cout<<max;
	return 0;
}
