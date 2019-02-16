#include <iostream>
#include <algorithm>
using namespace std;
int a[30]={1,2,3,5,8,13,21,34,55,89};
int main()
{
    int k,m,n,x,b;
    cin>>k>>m>>n;
    m=m-2;
    if(k>m) cout<<0<<endl;
    else
    {
        x=k/m;
        b=a[x+2];
        if(m%2!=0)
        {
            b=b+2*b;
        }
        cout<<b*(k%m+1)<<endl;
    }
}
