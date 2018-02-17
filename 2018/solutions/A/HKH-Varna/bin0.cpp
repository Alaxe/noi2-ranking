#include <iostream>
using namespace std;
int main ()
{
    long long int n,n2,br;
    long long int a,b,nul,f=0;
    cin>>a>>b>>nul;
    //a=1;b=10000000;nul=2;
    for(n2=b; n2>=a; n2--)
    {
        n=n2;
        br=0;
        //cout<<n2<<"-";
        for(; n; n/=2)
        {
           // cout<<n%2;
            if(n%2==0)br++;
            if(nul<br)n=0;
        }
        if(nul==br)
            f++;
        //cout<<" "<<br<<"\n";
    }
    cout<<f<<"\n";
    return 0;
}
