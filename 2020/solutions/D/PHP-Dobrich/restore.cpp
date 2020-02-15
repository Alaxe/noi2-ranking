#include<iostream>
using namespace std;

int main()
{
    int n, i, j, br=0;
    cin>>n;
    int a[n], b[n];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]<a[j])br++;
        }
        b[i]=br;
        br=0;
    }
    for(i=0;i<n-1;i++)cout<<b[i]<<" ";
    cout<<b[n-1]<<endl;
    return 0;
}
