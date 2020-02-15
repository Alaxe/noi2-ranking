#include<iostream>
using namespace std;

int main()
{
    short n, u, v, i, j, x=0, s=0;
    cin>>n>>u>>v;
    short a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        j=i+1;
        while(a[i]>a[j] && j<n)
        {
            if(a[i]-a[j]<a[i]-a[j+1])break;
            j++;
            s+=u;
        }
        if(a[i]<a[j])x+=(s*a[i]*v);
        else x+=(s*a[j]*v);
        s=u;
    }
    cout<<x<<endl;
    return 0;
}
