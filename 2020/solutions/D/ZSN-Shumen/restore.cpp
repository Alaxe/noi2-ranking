#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int n,b[100000];
int a[1000000];
int l_num(int i)
{
    int br=0;
    for(int j=i+1;j<n;j++)
    {
        if(a[i]<=a[j])br++;
    }
    return br;
}
void mass_min(int um)
{
    for(int i=0;i<n;i++)
    {
        a[i]-=um;
    }
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    a[n-1]=100;
    for(int i=n-2;i>=0;i--)
    {
        a[i]=101;
        cout<<a[i]<<endl;
        for(int j=0;j<99999;j++)
        {
            if(l_num(i)<b[i])a[i]--;
            if(l_num(i)==b[i])break;
            cout<<a[i]<<endl;
        }
    }
    int minn=100001;
    for(int i=0;i<n;i++)
    {
        if(a[i]<minn)minn=a[i];
    }
    int h=minn-1;
    mass_min(h);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
