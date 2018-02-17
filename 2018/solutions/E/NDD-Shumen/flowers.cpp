#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a;
    long long int maxx=-1;
    long long int q,sum=0;
    cin>>q;
    long long int a2;
    for(long long int i=0;i<n;i++)
    {
        cin>>a;
        if(a>maxx)maxx=a; 
        a2=a;
            for(long long int j=0;j<n;j++)
            {
                if(a!=maxx)sum+=((maxx-a2)*q);
            }
    } 
    cout<<sum<<endl;
return 0;
}