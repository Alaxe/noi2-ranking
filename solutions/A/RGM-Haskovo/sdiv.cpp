#include<iostream>
#include<cstring>
using namespace std;
long long n,m;
long long int d,ans=0;
string s;
void fff (int p, long long k)
{
    if (k%n==0) {ans=(ans+1)%m;}
    for (int j=p+1; j<d; j++)
    {
        fff(j,k*10+(s[j]-'0'));
    }
}

int main ()
{

    cin>>s;
    d=s.size();
    cin>>n>>m;
    for (int i=0; i<d; i++)
    {
        fff (i,s[i]-'0');
    }
    cout<<ans<<endl;
    return 0;
}
