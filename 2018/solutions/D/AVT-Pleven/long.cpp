#include<iostream>
using namespace std;
int main()
{
    long long n,k,b,k1=0,c;
    cin>>n>>k;
    b=1;
    for(int i=1; n-1>=i; i++)
    {
        b=b*10;
    }
    c=b;
    k1=b;
    for(int j=b; j<=k1*10; j++)
    {
        if(c%k==0)
        {
            break;
        }
      c=c+1;
    }
cout<<c<<endl;

    return 0;
}
