#include<iostream>
using namespace std;
int main()
{
int m,k,a;
cin>>m>>k;
int sum=0;
int min=a;
while (sum<k)
{
    cin>>a;
    int min=a;
    int sum=0;
    if (a%2==0)
    {
        sum=sum+a;
    }
    if (m-a<m-min)
    {
        min=a;
    }
}
cout<<min<<" "<<sum<<endl;
return 0;
}
