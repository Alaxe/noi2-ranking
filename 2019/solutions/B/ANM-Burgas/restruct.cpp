#include<iostream>
using namespace std;

const int maxi=5000;
int n, k;
int requests[maxi][maxi], l[maxi];

int main()
{
    cin>>n;
    cin>>k;
    for(int i=0; i<n; i++)
    {
        cin>>l[i];
        for(int j=0; j<l[i]; j++)
        {
            cin>>requests[i][j];
        }
    }
    cout<<n*k*2<<endl;
    return 0;
}
