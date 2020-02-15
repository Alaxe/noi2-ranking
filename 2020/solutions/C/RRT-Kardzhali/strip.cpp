#include<iostream>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    if(k==1||k==n)
    {
        cout<<1;
        return 0;
    }
    if((n-1)%2==0&&(k==n/2+1))
    {
        cout<<(n-1)*(n-2);
        return 0;
    }

}
