#include<iostream>
using namespace std;
int main ()
{
    long long int n,k,c=10;
    cin>>n>>k;
    long long int g=0;
    int p=n-2;
    while(p!=0)
    {
        c=10*c;
        p--;
    }
    if(n==2)c=10;
    for(int i=0; i<=c; i++)
    {
        if(c%k==0)g=c;
        else  c++;
    }
    cout<<g<<endl;
    return 0;
}
