#include<iostream>
using namespace std;

int main()
{
    long long int n,k=2,ch=1,br=1;
    cin>>n;
    while(k<n+1)
    {
        br=br+k+k-1;
        k++;
    }
    cout<<br-k+2<<endl;
    return 0;
}
