#include<iostream>
using namespace std;
int main()
{
long long int n;
cin>>n;
for(int i=0;i<n;i++)
int sum1=n/10;
int sum2=n/10%10;
int sum=sum1*sum2;
cout<<sum<<endl;
return 0;
}