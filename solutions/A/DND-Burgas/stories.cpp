#include<iostream>
using namespace std;
int main()
{
	unsigned long long n,k,first,mul,add,mod,max,sum,previous;
	sum = 0;
	cin>>n>>k>>first>>mul>>add>>mod;
	unsigned long long *arr = new unsigned long long[k];
	arr[0] = first;
	max = first;
	unsigned long long counter = 0;
	sum+=max;
	for(unsigned long long i=1;i<n;i++)
	{
		counter++;
		unsigned long long index = i%k;
		if(index!=0)
		{
			arr[index] = (arr[index-1]*mul+add)%mod;
	    }
	    else
	    {
	    	arr[index] = (arr[k-1]*mul+add)%mod;
		}
		//cout<<arr[index]<<endl;
		if(arr[index]>max)
		{
			//cout<<"da"<<max<<"<"<<arr[index]<<endl;
			max = arr[index];
			counter = 0;
		}
		if(counter==k)
		{
			max = 0;
			for(unsigned long long j=0;j<k;j++)
			{
				if(arr[j]>max)
				{
					//cout<<"Da";
					//cout<<max<<"<"<<arr[j]<<endl;
					max = arr[j];
				}
			}
			counter = 0;
		}
		//cout<<sum<<"+="<<max<<endl;
		sum += max;
	}
	cout<<sum<<endl;
	return 0;
}
