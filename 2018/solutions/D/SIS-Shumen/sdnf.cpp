#include<iostream>
using namespace std;
int main()
{
    unsigned long long int n,facn=1,sumcf=0,i;
    cin>>n;
    for(i=1;i<=n;i++)
        facn*=i;
    while(facn!=0)
    {
        sumcf+=(facn%10);
        facn/=10;
    }
    cout<<sumcf<<endl;
return 0;
}