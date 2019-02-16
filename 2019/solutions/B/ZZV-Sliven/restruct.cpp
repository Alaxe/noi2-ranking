#include <iostream>
//nikva ideq kvo trqbva da sa naprai
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n][n];
    for (int i=0;i<n;i++) {
        cin>>a[i][0];
        for (int k=1;k<=a[i][0];k++)
            cin>>a[i][k];
    }
    cout<<n*n*k/2;
}
