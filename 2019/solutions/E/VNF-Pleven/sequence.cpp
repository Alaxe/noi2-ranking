#include<iostream>
using namespace std;

long long n,k=1,i,j=2,j2,b;

int main()
{
    cin>>n;
    for(i=2;i<=n;i++){
        b=b+j;
        j=j+2;
    }
    cout<<b+1;
    return 0;
}
