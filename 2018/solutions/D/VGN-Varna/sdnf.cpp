#include<iostream>
using namespace std;
int main()
{
    long long int n,i,br=0,sum=1,l,j,p=1;
    cin>>n;
    l=n;
    for(i=1;i<=l;i++)
    {
    sum=sum*p;
    p++;
    }

   for(j=sum;j>0;j/=10){
    br=br+sum%10;
    sum=sum/10;

    }
    cout<<br;

}
