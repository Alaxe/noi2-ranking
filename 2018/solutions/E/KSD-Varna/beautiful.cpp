#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,k,m=0,purc=1,posc=9,i;
    cin>>n>>k;
    while(n>1)
    {
        purc*=10;
        posc=posc*10+9;
        n--;
    }
    for(i=purc;i<=posc;i++)
    {
        if(i%k==0)
        {
            m=i;
            break;
        }
    }
    if(m==0) cout<<"NO"<<endl;
    else cout<<m<<endl;
    return 0;
}
