#include<iostream>
using namespace std;
int a[128],n,u,v;
void read()
{
    cin>>n>>u>>v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
int main()
{
    int sum=0,d;
    read();
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i-1]&&a[i]<a[i+1])i++;
        if(a[i]>a[i+1]&&a[i+2]>a[i+1])
        {
            if(a[i]<a[i+2])d=a[i]*u*(v+v);
            else d=a[i+2]*u*(v+v);
        }
        else
        {
            if(a[i]<a[i+1])d=a[i]*u*v;
            else d=a[i+1]*u*v;
        }
        sum+=d;
    }
    cout<<sum<<endl;
    return 0;
}
