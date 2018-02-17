#include<bits/stdc++.h>
using namespace std;
unsigned long long a=1;
int n,s,idub;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        idub=i;
        a*=idub;
        while(idub%5==0 && idub!=0){a/=10;idub/=5;}
    }
    ///cout<<a<<endl;
    while(a)
    {
        s+=a%10;
        a/=10;
    }
    cout<<s<<endl;
}
