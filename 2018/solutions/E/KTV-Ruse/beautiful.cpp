#include <iostream>
using namespace std;
int main()
{
    long long n,k,m=1;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        m=m*10;
    }
    for(int j=m;j<=m*9;j++)
    {
        if(j%k==0){cout<<j<<endl; break;}
        
        
    }
    
    return 0;
}