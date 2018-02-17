#include<iostream>
using namespace std;
int main()
{
    long long int m, n, br=0;
    cin>>m>>n;
    for(m; m<n; m++)
    {
        if(m*m+1<=n) br++;
    }
    cout<<br<<endl;
}

