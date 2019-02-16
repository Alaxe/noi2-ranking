#include<iostream>
using namespace std;
int main()
{
    int K,n,a[1000000],i;
    cin>>n;
    a[0]=1;
    for (i=1;i<n;i++){
        if (a[i]=n)
            cout<<i;
        if(a[i+1]=n)
            cout<<i+1;
        cin>>a[i];

    }
    return 0;

}
