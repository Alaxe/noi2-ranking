#include<iostream>
using namespace std;
int main()
{
    int n,i,a=0,b=0,p=-1;
    cin>>n;
    int k[n*2];
    for(i=0; i<n*2; i++) cin>>k[i];
    for(i=0; i<2*n-2; i++)
    {
        if(i%2==0) p=1;
        if(k[i]==k[n*2-2]&&k[i+p]!=k[n*2-1]) a++;
    }
    for(i=0; i<2*n-2; i++)
    {
        if(i%2==0) p=1;
        if(k[i]==k[n*2-1]&&k[i+p]!=k[n*2-2]) b++;
    }
    i=b;
    if(a<b)i=a;
    cout<<2*i<<endl;
}
