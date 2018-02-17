#include<iostream>
using namespace std;
int main()
{
    int n,q,i,k,max1=0,S=0,maxall=0;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>k;
        if (max1<k) max1=k;
        S=S+k;
    }

    cin>>q;
    maxall=max1*n;
    S=maxall-S;
    cout<<S<<endl;
    cout<<S*q<<endl;
    return 0;
}
