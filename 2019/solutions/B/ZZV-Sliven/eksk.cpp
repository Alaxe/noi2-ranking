#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[2];
    for (int i=0;i<n;i ++){
        cin>>a[0]>>a[1];
    }
    if (n==2||n/2-(min(a[0],a[1])-1)/2==0)
        cout<<1;
    else
        cout<<n/2-(min(a[0],a[1])-1)/2;
}

