#include <iostream>
using namespace std;
int main()
{
    long long n,k,i=0,dokude=1,otkude=1;
    cin>>n>>k;
    bool dali=false;
    for(i=0; i<n; i++)
    {
        dokude=dokude*10;
    }
    i=1;
    otkude=dokude/10-1;

    while(dali==false)
    {
        if(i>otkude and i<dokude and i%k==0)
        {
            dali=true;
            cout<<i<<endl;
        }
        if(i>9999999)
        {
            cout<<"NO"<<endl;
            dali=true;
        }
        i++;
    }
    return 0    ;
}

